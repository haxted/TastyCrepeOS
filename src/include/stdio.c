#include <stdio.h>
static const unsigned char font[] = {
#embed "font.bin"
};
unsigned char* fontmem = (unsigned char*)0xA0000;

int pos = 0;
char* bfr = (char*)0xb8000;
void kputc(char c, uint8_t color) {

	if(c == '\n') {
		pos += (80 - (pos % 80));
	}
	bfr[pos * 2] = c;
	bfr[pos * 2 + 1] = color;
	pos++;

}



void kputs(const char *str) {
	while(*str){
		kputc(*str++, 0x07);
	}
	kputc('\n', 0);
}

void clrscrC(uint8_t color) {
	for(int i = 0; i < 80*25; i++) {
		kputc(' ', color);
		
			
	}
}
void clrscr() {
	for(int i = 0; i < 80*25; ++i) {
		kputc(' ', 0x07);
	}
}

void NewFont() {
	for(int x = 0; x < 4096; x++) {
		fontmem[x] = font[x];
	}
}

void kprintf(const char* str) {
	while(*str) {
		kputc(*str++, 0x07);
	}
}

void printr(char c, int wid, int hei, unsigned char color) {
	for(int s = 0; s < wid*hei; s++) {
		kputc(c, color);
		if((s+1) % wid == 0) {
			kputc('\n', 0);
		}
	}
}
