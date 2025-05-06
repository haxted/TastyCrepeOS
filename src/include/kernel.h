#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "1.1.0a"
#define TC_BUILD "19250"
#define TC_MOTB "Github pls remove that 50% C++ :pray:"
#include <string.h>

extern void panic(const char* r);

void kmain(string cpuid1, string cpuid2, string cpuid3);
int welcome(void);
#endif
