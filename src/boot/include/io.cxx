#include "io.hxx"


namespace Io {
  uint8_t inb(uint16_t port) {
  uint8_t out;
    __asm__ volatile("inb %1, %0" :  "=a"(out) : "dN"(port));
    return out;
  }
  void outb(uint16_t port, uint8_t val) {
    __asm__ volatile("outb %0, %1" : : "a"(val), "dN"(port));
  }
};
