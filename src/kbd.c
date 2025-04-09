#include <kbd.h>


void setScancodeSet(uint8_t scst) {
	outb(0xf0, PS2_DATA);
}



