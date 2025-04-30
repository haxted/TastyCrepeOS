#ifndef SYSCALLS_H
#define SYSCALLS_H
#include <idt.h>
#include <kernel.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <io.h>

typedef struct {
	uint32_t eax;
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
	uint32_t esi;
	uint32_t edi;
} syscallFrame;

extern void int80hstb();
void initsyscalls();
void syscall(syscallFrame *frame);

#endif

