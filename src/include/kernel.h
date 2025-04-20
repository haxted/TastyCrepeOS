#ifndef KERNEL_H
#define KERNEL_H
#define TC_VER "0.9.0a"
#define TC_BUILD "17253"
#define TC_MOTB "if(errors) return toBed;"

void kmain(void);
void panic(const char *r);
int welcome(void);
#endif
