#ifndef STRING_H
#define STRING_H
#include <stdint.h>

typedef const char* string;
void memcpyb(void* dest, const void* src, int sz);
void memcpyw(void* dest, const void* src, int sz);
void memcpyd(void* dest, const void* src, int sz);


#endif
