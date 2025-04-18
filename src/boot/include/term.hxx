#ifndef _TERM_HPP
#define _TERM_HPP
using string = const char*;

namespace Term {
  void term_outc(char c);
  void term_outs(string str);
  void clrscr();
}

#endif /* _TERM_HPP */
