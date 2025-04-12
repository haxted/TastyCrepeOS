#include <kbd.h>
#include <idt.h>

void initKbd() {
	addIDTEntry(1, (void*)KbdTakeInputPA, 0x8e);
}
