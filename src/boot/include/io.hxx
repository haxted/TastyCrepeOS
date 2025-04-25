#ifndef _IO_HPP
#define _IO_HPP
#include <cstdint>
extern "C" {
uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t val);
}

#endif
