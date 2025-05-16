#ifndef KBD_H
#define KBD_H
#include <io.h>
#include <stdint.h>

#define PS2_DATA 0x60
#define PS2_STATUS 0x64


void initKbd();
char KbdTakeInput();
uint8_t KbdTakeInputD();
void kbdFunc(int func);
extern void KbdTakeInputPA();

// HELLO AMERICA!

#endif

