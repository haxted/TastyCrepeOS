#include <kbd.h>
#include <idt.h>

char ps2Scancodes[128] = {
	0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0, 0, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', 0, 0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '`', 0, '\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', 0, '*', 0 
}

void initKbd() {
	addIDTEntry(1, (uint32_t)KbdTakeInputPA, 0x8e);
}

char KbdTakeInput() {
	char c = inb(PS2_DATA);
	return ps2Scancodes[c];
}

uint8_t KbdTakeInputD() {
	return inb(PS2_DATA);
}

void kbdFunc(int func) {
	switch(func) {
		case 0: KbdTakeInput(); break;
		case 1: KbdTakeInputD(); break;
		default: return;
	}
}
