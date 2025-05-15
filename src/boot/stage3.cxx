/*
HorrifyingBoot v0.1.2
Stage 3, C++ section
Made by: haxted
*/
#define KRNL_LD 0x100000


#include "include/term.hxx"
#include "include/ata.hxx"
#include "include/idt.hxx"
#include "include/elf.hxx"
#include "include/kbd.hxx"
#include <iso646.h>
extern "C" char* framebufferaddr;


extern "C" void bmain(uint32_t framebuff) {
  framebufferaddr = (char*)framebuff;
  startscr();

  //Term::clrscr();
  Disk::ata_init();
  initkbd();
  initIDT();
  //Term::term_outs("Entered C++ section");
  //Term::term_outc('\n');
  Disk::ata_rdisk(56, 65, KRNL_LD); // Reads the kernel into memory from sector 56
  //Term::term_outs("Loaded the kernel");
  //Term::term_outc('\n');
  //Term::term_outs("HorrifyingBoot v0.1.1");
  //Term::term_outc('\n');
  elf_load(KRNL_LD);
  jmpelf();
  
}

void startscr() {
  char r = 0;
  char g = 0;
  char b = 0;
  for(int x = 0; x < 1280; x++) {
    for(int y = 0; y < 1024; y++) {
      plotpx(x, y, r, g, b);
      r++;
      g++;
      b++;
      if(r > 255 or g > 255 or b > 255) {
        r = 0;
        g = 0;
        b = 0;
      }
    }
  }
}
