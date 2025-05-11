#pragma once
#include <stdint.h>


typedef struct {
    uint8_t priority;
    uint16_t count;
    uint8_t child;
} __attribute__((packed)) PID;

typedef struct {
    int eax, ebx, ecx, edx, esi, edi, esp, ebp, eip, eflags;
} __attribute__((packed)) regs;

typedef struct task {
    PID pid;
    regs reg;
    struct task *n;
} __attribute__((packed)) Task;

