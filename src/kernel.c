#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <kernel.h>

void kmain(void) {
	puts("The system will panic shortly for testing.\n");
	panic("Test panic, system halted");
	for(;;);

}

void panic(const char *r) {
	puts("Kernel panic: ");
	puts(r);
	while(1){	
		asm("hlt");
	}
}

