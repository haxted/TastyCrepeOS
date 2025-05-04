#pragma once
#include <cstdint>
#include "memcpy.hxx"
#include "term.hxx"
#include "hlt.hxx"

#define ERR_NOTYPE "Kernel has no type, halting"
#define ERR_NOMACHINE "Kernel has no machine(?), halting"
#define ERR_WRONGARCH "Kernel has a bad architecture, halting"


typedef uint32_t ElfAddr;
typedef uint16_t ElfHalf;
typedef int32_t ElfSword;
typedef uint32_t ElfWord;
typedef uint32_t ElfOff;

typedef struct {
  unsigned char e_ident[16];
  ElfHalf e_type;
  ElfHalf e_machine;
  ElfWord e_version;
  ElfAddr e_entry;
  ElfOff e_phoff;
  ElfOff e_shoff;
  ElfWord e_flags;
  ElfHalf eh_size;
  ElfHalf e_phentsize;
  ElfHalf e_phnum;
  ElfHalf e_shentsize;
  ElfHalf e_shnum;
  ElfHalf e_shstrndx;
} __attribute__((packed)) ElfHdr;

typedef struct {
  ElfWord p_type;
  ElfOff p_offset;
  ElfAddr p_vaddr;
  ElfAddr p_paddr;
  ElfWord p_filesz;
  ElfWord p_memsz;
  ElfWord p_flags;
  ElfWord p_align;
} __attribute__((packed)) ElfPhdr;

int elf_load(uint32_t elf_memlocation);
void jmpelf();

