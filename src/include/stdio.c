#include <stdio.h>
static const unsigned char font[] = {
#embed "font.bin"
};
unsigned char* fontmem = (unsigned char*)0xA0000;

int pos = 0;
char* bfr = (char*)0xb8000;
void putc(char c) {

	if(c == '\n') {
		pos += (80 - (pos % 80));
	}
	bfr[pos * 2] = c;
	bfr[pos * 2 + 1] = 0x0F;
	pos++;

}



void puts(const char *str) {
	while(*str){
		putc(*str++);
	}
	putc('\n');
}

void clrscr() {
	for(int i = 0; i < 80*25; ++i) {
		putc(' ');
	}
}

void NewFont() {
	for(int x = 0; x < 4096; x++) {
		fontmem[x] = font[x];
	}
}



