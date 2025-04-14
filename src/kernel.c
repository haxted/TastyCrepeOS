#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <kernel.h>
#include <idt.h>
#include <io.h>
#include <syscalls.h>

void kmain(void) {
	initidt();
	initsyscalls();
	clrscr();
	NewFont();
	welcome();
	

	for(;;);

}

void panic(const char *r) {
	clrscr();
	kprintf("Kernel panic: ");
	kputs(r);
	for(;;) {	
		__asm__("cli; hlt");
	}
}

int welcome(void) {
	kputs("Welcome to the TastyCrepeOS kernel!");
        kprintf("Build number ");
        kputs(TC_BUILD);
        kprintf("Version: ");
        kputs(TC_VER);
	return 0;
}


