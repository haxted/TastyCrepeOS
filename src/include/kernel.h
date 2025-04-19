#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "0.8.4a"
#define TC_BUILD "18252"
#define TC_MOTB "1 pro, 1006 cons"

void kmain(void);
void panic(const char *r);
int welcome(void);
#endif
