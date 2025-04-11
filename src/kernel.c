#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <kernel.h>
#include <idt.h>
#include <io.h>

void kmain(void) {
	initidt();
	welcome();

	for(;;);

}

void panic(const char *r) {
	puts("Kernel panic: ");
	puts(r);
	for(;;) {	
		asm("cli; hlt");
	}
}

int welcome(void) {
	puts("Welcome to the TastyCrepeOS kernel");
        puts("Build number ");
        puts(TC_BUILD);
        puts("Version: ");
        puts(TC_VER);
	return 0;
}


