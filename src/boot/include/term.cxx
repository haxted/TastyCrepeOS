#include "term.hxx"

namespace Term {
char *vidmem = (char*)0xB8000;
int pos = 0;

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

} // namespace Term

