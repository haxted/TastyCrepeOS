#pragma once
#include <stdint.h>
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

extern void writes(const char* str);
extern void writer(char c, int wid, int hei, loc_t* loc, rgb_t* rgb);
extern void clrs();
extern void clrscol(rgb_t* rgb);
extern void videofunc(int func, videoParam_t* params);
extern void kbdfunc(int func);