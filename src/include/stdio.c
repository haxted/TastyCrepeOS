#include <stdio.h>
int pos = 0;

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
}



