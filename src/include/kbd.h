#ifndef KBD_H
#define KBD_H
#include <io.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <kernel.h>

#define PS2_DATA 0x60
#define PS2_STATUS 0x64


void initKbd();
void KbdTakeInput();
void KbdTakeInputP();
extern void KbdTakeInputPA();

// HELLO AMERICA!

#endif

