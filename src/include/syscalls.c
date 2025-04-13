#include <syscalls.h>


void initsyscalls() {
	setIDTEntry(0x80, (uint32_t)int80hstb, 0x8e);
}
