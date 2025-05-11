#pragma once

#include <process.h>
#include <stdlib.h>
#include <stdio.h>

extern void getEFLAGS();
extern void switchtsk(Task* to, Task* from)
int createTask(Task *tsk, void(*mn)(), uint32_t flags);
int initTasks();
void yield();