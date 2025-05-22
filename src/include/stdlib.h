#include <stdint.h>
#include <kernel.h>
#include <stddef.h>
#ifndef STDLIB_H
#define STDLIB_H

typedef struct {
    uint8_t* stackBase;
    size_t offset;
    size_t size;
} __attribute__((packed)) stackAllocator;




void stackInit(stackAllocator* stack, size_t size, uint8_t* mem);
void* malloc(size_t size, stackAllocator* stack);
void free(stackAllocator* stack, size_t size);
#endif
