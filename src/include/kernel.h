#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "0.6-2a"
#define TC_BUILD "16252"
#define TC_MOTB "Now with good fonts!"

void kmain(void);
void panic(const char *r);
int welcome(void);
#endif
