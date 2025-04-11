#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "0.6a"
#define TC_BUILD "15250"
#define TC_MOTB "Making square wheels to better admire the round ones"

void kmain(void);
void panic(const char *r);
int welcome(void);
#endif
