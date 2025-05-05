#pragma once
#include <stdint.h>
#include "idt.hxx"

extern "C" {
char kbdin();
uint8_t kbdindbg();
void initkbd();
}
