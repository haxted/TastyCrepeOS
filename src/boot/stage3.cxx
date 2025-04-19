#include "include/term.hxx"
#include <cstdint>
#include <iso646.h>

extern "C" void bmain() {
  Term::clrscr();
  Term::term_outs("Entered C++ section");
}


