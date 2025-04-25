#include "elf.hxx"

ElfHdr hdr;
ElfPhdr phdr;

 int elf_load(uint32_t elf_memlocation) {
  elf_memlocation += 16;
  uint32_t* addr = (uint32_t*)elf_memlocation;
  hdr.e_type = *(uint16_t*)addr;
  switch(hdr.e_type) {
    case 0: return 1; Term::term_outs(ERR_NOTYPE); hlt();
    case 1: return 1; Term::term_outs("Error: error"); hlt();
    case 2: break;
    default: return 1; hlt();
  }
  elf_memlocation += sizeof(ElfHalf);
  addr = (uint32_t*)elf_memlocation;
  hdr.e_machine = *(uint16_t*)addr;

  switch(hdr.e_machine) {
    case 0: return 3; Term::term_outs(ERR_NOMACHINE); hlt();
    case 1: return 2; Term::term_outs(ERR_WRONGARCH); hlt();
    case 2: return 2; Term::term_outs(ERR_WRONGARCH); hlt();
    case 3: return 0; Term::term_outs("Arch ok, continuing"); break;
    default: return 2; Term::term_outs(ERR_WRONGARCH); hlt();
    
  }
  elf_memlocation += sizeof(ElfHalf);
  addr = (uint32_t*)elf_memlocation;
  hdr.e_version = *(uint32_t*)addr;

  switch(hdr.e_version) {
    case 1: return 0; break;
    default: Term::term_outs("Invalid elf version"); hlt();
  }
  elf_memlocation += sizeof(ElfWord);
  addr = (uint32_t*)elf_memlocation;
  hdr.e_entry = *(uint32_t*)addr;

  switch(hdr.e_entry) {
    case 0: Term::term_outs("Invalid entry point");
    default: return 0; break;
  }
  elf_memlocation += sizeof(ElfAddr);
  addr = (uint32_t*)elf_memlocation;
  hdr.e_phoff = *(ElfOff*)addr;
  // Dont even try to think about what this does

  uint32_t phdr_addr = (elf_memlocation - (sizeof(ElfHalf) + 16 + sizeof(ElfHalf) + sizeof(ElfHalf) + sizeof(ElfWord) + sizeof(ElfAddr))) + hdr.e_phoff;
  
  // Does some stuff. I don't understand this either.
  elf_memlocation += sizeof(ElfOff);
  elf_memlocation += sizeof(ElfOff);
  elf_memlocation += sizeof(ElfWord);
  addr = (uint32_t*)elf_memlocation;
  hdr.eh_size = *(ElfHalf*)addr;

  elf_memlocation += sizeof(ElfHalf);
  addr = (uint32_t*)elf_memlocation;
  hdr.e_phentsize = *(ElfHalf*)addr;

  elf_memlocation += sizeof(ElfHalf);
  addr = (uint32_t*)elf_memlocation;
  hdr.e_phnum = *(ElfHalf*)addr;
  phdr_addr += sizeof(ElfWord);
  
  uint32_t* phdr_actualaddr = (uint32_t*)phdr_addr;
  phdr.p_offset = *(ElfOff*)phdr_actualaddr;

  uint32_t fileplaceidk = (elf_memlocation - 0x2C);
  uint32_t* actualfileplace = (uint32_t*)fileplaceidk;

  phdr_addr += sizeof(ElfOff);
  phdr_actualaddr = (uint32_t*)phdr_addr;
  phdr.p_vaddr = *(ElfAddr*)phdr_actualaddr;

  phdr_addr += sizeof(ElfAddr);
  phdr_actualaddr = (uint32_t*)phdr_addr;
  phdr.p_filesz = *(ElfWord*)phdr_actualaddr;

  for(int i = 0; i < hdr.e_phnum; i++) {
    memcpy((void*)phdr.p_vaddr, (void*)actualfileplace, phdr.p_filesz);
  }
  
  
  
  
  

  
  
  

  
  return 0;
}
