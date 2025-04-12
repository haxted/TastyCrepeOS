#include <syscalls.h>


void initsyscalls() {
	setIDTEntry(0x80, (void*)int80hstb, 0x8e);
}
