#pragma once

#include <process.h>
#include <stdlib.h>
#include <stdio.h>

extern int getEFLAGS();
extern void switchtsk(regs* to, regs* from);
int createTask(Task *tsk, void(*mn)(), uint32_t flags);
int initTasks();
void yield();