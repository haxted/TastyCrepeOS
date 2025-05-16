#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "1.2.1a"
#define TC_BUILD "2025UC"
#define TC_MOTB "Don't forget to free after you allocate memory!"
#include <string.h>

extern void panic(const char* r);

void kmain(string cpuid1, string cpuid2, string cpuid3);
int welcome(void);
#endif
