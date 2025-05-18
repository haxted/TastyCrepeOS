#include <stdlib.h>

void stackInit(stackAllocator* stack, size_t size, uint8_t* mem) {
        stack->stackBase = mem;
        stack->size = size;
        stack->offset = 0;
}

void* malloc(size_t size, stackAllocator* stack) {
        if(stack->offset + size > stack->size) {
                panic("Stack allocator size overflow");
                return NULL;
        }
        void* memptr = stack->base + stack->offset;
        stack->offset += size;
        return memptr;
}

void free(stackAllocator* stack, size_t size) {
        if(size > stack->offset) {
                return;
        }
        stack->offset -= size;
}
