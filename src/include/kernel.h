#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "1.3.0a"
#define TC_BUILD "20251"
#define TC_MOTB "if(!works) work();"
#include <string.h>

extern void panic(const char* r);

void kmain(string cpuid1, string cpuid2, string cpuid3, int framebuffer_addr);
int welcome(void);
#endif
