#ifndef SYSCALLS_H
#define SYSCALLS_H
#include <idt.h>
#include <kernel.h>
#include <stdio.h>

extern void int80hstb();
extern void systmcall();
void initsyscalls();

#endif

