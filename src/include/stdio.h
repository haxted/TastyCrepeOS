#ifndef STDIO_H
#define STDIO_H
#include <stdint.h>
extern uint8_t* framebufferaddr;


typedef struct {
    int x;
    int y;
} __attribute__((packed)) loc_t;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} __attribute__((packed)) rgb_t;

typedef struct {
    const char* str;
    loc_t* location;
    rgb_t* colort;
    char c;
    int wid;
    int hei;
} __attribute__((packed)) videoParam_t;

void kputs(const char *str);
void kputc(char c, rgb_t* color, loc_t* loc);
void clrscr();
int putpx(loc_t loc, rgb_t rgb);
void clrscrC(uint8_t color);
void kprintf(const char *str);
void printr(char c, int wid, int hei, rgb_t* color, loc_t* loc);
void videoFunc(int func, videoParam_t* params);
#endif
