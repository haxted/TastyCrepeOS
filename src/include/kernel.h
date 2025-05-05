#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "1.0.0a"
#define TC_BUILD "18250"
#define TC_MOTB "The Worse Operating System"
#include <string.h>

void kmain(string cpuid1, string cpuid2, string cpuid3);
void panic(const char *r);
int welcome(void);
#endif
