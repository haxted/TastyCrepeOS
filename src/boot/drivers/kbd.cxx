#include "../include/kbd.hxx"
#include "../include/io.hxx"
unsigned char kbdmap[128] = {
  1, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 14, 15, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', 0x1C, 0x1D, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', 39, '`', 0x2A, '\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '.', '/', 0x36, '*', 0
};
extern "C" void kbdst();
extern "C" {

char kbdin() {
  unsigned char scancode = inb(0x60);
  if(scancode < 0x80) {
    return kbdmap[scancode];
  }
  return 0;
}

uint8_t kbdindbg() {
  uint8_t scancode = inb(0x60);
  if(scancode < 0x80) {
    return scancode;
  }
  return 0;
}
 void initkbd() {
  setEntry(0x09, (uint32_t*)kbdst, 0x8E);
}
}
