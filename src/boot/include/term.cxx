#include "term.hxx"
#include <iso646.h>

namespace Term {
//char *vidmem = (char*)0xB8000;
//int pos = 0;
char* framebufferaddr;

/*
void term_outc(char c) {
  if (c == '\n') {
    pos += (80 - (pos % 80));
  }
  vidmem[pos * 2] = c;
  vidmem[pos * 2 + 1] = 0x07;
}

void term_outs(string str) {
  while(str) {
    term_outc(*str++);
  }
}
void clrscr() {
  for(int i = 0; i < 80*25; i++) {
    term_outc(' ');
  }
}
*/
int plotpx(int x, int y, char r, char g, char b) {
  if(x > 1280 or x < 0 or y > 1024 or y < 0) return 1;
  int off = (y * 1280 + x);
  framebufferaddr[off * 3] = r;
  framebufferaddr[off * 3 + 1] = g;
  framebufferaddr[off * 3 + 2] = b;
  return 0;
}
} // namespace Term

