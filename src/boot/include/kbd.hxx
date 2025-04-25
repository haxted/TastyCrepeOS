#pragma once
#include <cstdint>
#include "idt.hxx"

extern "C" {
char kbdin();
uint8_t kbdindbg();
void initkbd();
}
