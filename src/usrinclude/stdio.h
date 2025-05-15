#pragma once
#include <stdint.h>
typedef struct {
    int x;
    int y;
} __attribute__((packed)) loc_t;

extern void writes(const char* str);
extern void writef(const char* str);
extern void writer(char c, int wid, int hei, uint8_t color);
extern void clrs();
extern void clrscol(uint8_t color);
