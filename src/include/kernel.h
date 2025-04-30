#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "1.0.0a"
#define TC_BUILD "18250"
#define TC_MOTB "The Worse Operating System"

void kmain(void);
void panic(const char *r);
int welcome(void);
#endif
