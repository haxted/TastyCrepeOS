#include <io.h>

uint8_t inb(uint16_t port) {
	uint8_t res;
	asm volatile("inb %1, %0" :
			"=a"(res) : "d"(port));
	return res;
}

void outb(uint16_t port, uint8_t val) {
	asm volatile("outb %0, %1" : : "a"(val), "d"(port));
}
uint16_t inw(uint16_t port) {
	uint16_t res;
	asm volatile("inw %1, %0" :
			"=a"(res) : "d"(port));
	return res;
}

void outw(uint16_t port, uint16_t val) {
	asm volatile("outw %0, %1" : : "a"(val), "d"(port));
}
