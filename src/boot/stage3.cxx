/*
HorrifyingBoot v0.1.0
Stage 3, C++ section
Made by: haxted
*/
#define KRNL_LD 0x100000


#include "include/term.hxx"
#include "include/ata.hxx"
#include "include/idt.hxx"
#include "include/elf.hxx"
#include <iso646.h>

extern "C" void jmpkrnl();

extern "C" void bmain() {
  Term::clrscr();
  initIDT();
  Term::term_outs("Entered C++ section");
  Term::term_outc('\n');
  Disk::ata_init();
  Disk::ata_rdisk(56, 57, KRNL_LD); // Reads ehhh into uhhhh from ermmmm
  Term::term_outs("Loaded the kernel");
  Term::term_outc('\n');
  Term::term_outs("HorrifyingBoot v0.1.0");
  Term::term_outc('\n');
  elf_load(KRNL_LD);
  jmpkrnl();
  
}


