#include "hlt.hxx"

void hlt() {
  for(;;) {
    __asm__ volatile("cli; hlt");
  }
}
