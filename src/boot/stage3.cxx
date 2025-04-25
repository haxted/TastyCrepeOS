/*
HorrifyingBoot v0.1.1
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

extern "C" void jmpkrnl();

extern "C" void bmain() {
  Term::clrscr();
  Disk::ata_init();
  initkbd();
  initIDT();
  Term::term_outs("Entered C++ section");
  Term::term_outc('\n');
  Disk::ata_rdisk(56, 57, KRNL_LD); // Reads ehhh into uhhhh from ermmmm
  Term::term_outs("Loaded the kernel");
  Term::term_outc('\n');
  Term::term_outs("HorrifyingBoot v0.1.1");
  Term::term_outc('\n');
  elf_load(KRNL_LD);
  jmpkrnl();
  
}


