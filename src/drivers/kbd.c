#include <kbd.h>
#include <idt.h>

void initKbd() {
	addIDTEntry(1, (uint32_t)KbdTakeInputPA, 0x8e);
}
