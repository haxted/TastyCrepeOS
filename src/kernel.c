#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <kernel.h>
#include <idt.h>
#include <io.h>
#include <syscalls.h>
#include <string.h>

void kmain(string cpuid1, string cpuid2, string cpuid3) {
	NewFont();
	initidt();
	initsyscalls();
	clrscr();
	welcome();
	kprintf("Vendor String: ");
	kprintf(cpuid1);
	kprintf(cpuid2);
	kputs(cpuid3);

	for(;;);

}


int welcome(void) {
	kputs("Welcome to the TastyCrepeOS kernel!");
    kprintf("Build number: ");
    kputs(TC_BUILD);
	kprintf("Version: ");
    kputs(TC_VER);
	return 0;
}


