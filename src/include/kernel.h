#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "1.2.0a"
#define TC_BUILD "20250"
#define TC_MOTB "This OS cannot be run in DOS mode."
#include <string.h>

extern void panic(const char* r);

void kmain(string cpuid1, string cpuid2, string cpuid3);
int welcome(void);
#endif
