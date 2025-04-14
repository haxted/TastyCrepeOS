#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "0.7-1a"
#define TC_BUILD "16254"
#define TC_MOTB "Windows incoming..."

void kmain(void);
void panic(const char *r);
int welcome(void);
#endif
