#ifndef STRING_H
#define STRING_H
#include <stdint.h>

typedef const char* string;
void memcpyb(void* dest, const void* src, int sz);
void memcpyw(void* dest, const void* src, int sz);
void memcpyd(void* dest, const void* src, int sz);

// lazies
int peek(uint32_t addr);
void poke(uint32_t addr, uint8_t val);


#endif
