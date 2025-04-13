#include <stdio.h>
static const unsigned char font[] = {
#embed "font.bin"
};
unsigned char* fontmem = (unsigned char*)0xA0000;

int pos = 0;
char* bfr = (char*)0xb8000;
void kputc(char c) {

	if(c == '\n') {
		pos += (80 - (pos % 80));
	}
	bfr[pos * 2] = c;
	bfr[pos * 2 + 1] = 0x0F;
	pos++;

}



void kputs(const char *str) {
	while(*str){
		kputc(*str++);
	}
	kputc('\n');
}

void clrscr() {
	for(int i = 0; i < 80*25; ++i) {
		kputc(' ');
	}
}

void NewFont() {
	for(int x = 0; x < 4096; x++) {
		fontmem[x] = font[x];
	}
}

void kprintf(const char* str) {
	while(*str) {
		kputc(*str++);
	}
}

