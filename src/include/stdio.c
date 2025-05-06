#include <stdio.h>
extern inline void _setupVGA();
extern inline void _restore();

static const unsigned char font[] = {
#embed "font.bin"
};
unsigned char* fontmem = (unsigned char*)0xA0000;

int pos = 0;
char* bfr = (char*)0xb8000;
void kputc(char c, uint8_t color) {
	if(pos >= 80*25) {
		clrscr();
	} else {
	if(c == '\n') {
		pos += (80 - (pos % 80));
	}
	
	bfr[pos * 2] = c;
	bfr[pos * 2 + 1] = color;
	pos++;
	}
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
	pos = 0;
}
void clrscr() {
	for(int i = 0; i < 80*25; ++i) {
		kputc(' ', 0x07);
	}
	pos = 0;
}

void NewFont() {
	_setupVGA();
	for(int x = 0; x < 4096; x++) {
		fontmem[x] = font[x];
	}
	_restore();
}

void kprintn(int n, char color) {
	char buf[11];
	int i = 0;
	if(n == 0) buf[i++] = '0';
	else {
		while(n) {
			buf[i++] = '0' + (n % 10);
			n /= 10;
		}

	}
	for(int k = 0; k < i; k++) {
		bfr[k * 2] = buf[i - k - 1];
		bfr[k * 2 + 1] = color;
	}

}

void kprintf(int q, const char* str) {
	switch(q) {
		case 0: break;
		case 1: kputc('[', 0xFC); kputc('E', 0xFC); kputc(']', 0xFC); return;
	}
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
