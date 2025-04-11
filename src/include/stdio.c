#include <stdio.h>
#include <io.h>

int pos = 0;
char* bfr = (char*)0xb8000;
void putc(char c) {
	outb(0x3f8, c);

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



