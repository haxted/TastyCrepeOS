/*
HorrifyingBoot v0.1.0
Stage 3, C++ section
Made by: haxted
*/
#define KRNL_LD 0x100000


#include "include/term.hxx"
#include "include/ata.hxx"
#include "include/idt.hxx"
#include <iso646.h>

#if defined(__linux__)
#define NULL ((void*)0)
int *freeGTAV = NULL;
*freeGTAV = 69420;
#endif

extern "C" void bmain() {
  Term::clrscr();
  Term::term_outs("Entered C++ section");
  Term::term_outc('\n');
  Disk::ata_init();
  Disk::ata_rdisk(39, 61, KRNL_LD); // Reads ehhh into uhhhh from ermmmm
  Term::term_outs("Loaded the kernel");
  Term::term_outc('\n');
  Term::term_outs("HorrifyingBoot v0.1.0");
  Term::term_outc('\n');
  
  
  
}


