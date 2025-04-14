#ifndef STDIO_H
#define STDIO_H
#include <stdint.h>


void kputs(const char *str);
void kputc(char c, uint8_t color);
void clrscr();
void clrscrC(uint8_t color);
void kprintf(const char *str);
void NewFont();
void printr(char c, int wid, int hei, uint8_t color);
#endif
