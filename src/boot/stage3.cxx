/*
HorrifyingBoot v0.1.0
Stage 3, C++ section
Made by: haxted
*/



#include "include/term.hxx"
#include "include/ata.hxx"
#include <cstdint>
#include <iso646.h>

#if defined(__linux__)
#endif

extern "C" void bmain() {
  Term::clrscr();
  Term::term_outs("Entered C++ section");
  Term::term_outc('\n');
  Disk::ata_rdisk(39, 61, 0x100000); // Reads ehhh into uhhhh from ermmmm
  Term:;term_outs("Loaded the kernel");
  Term::term_outc('\n');
  Term::term_outs("Strike C to continue and load the ELF, strike P to see the CPUID, strike R to triple fault, strike X to launch BootSH");
  
}


