#include <stdint.h>
#include <kernel.h>
#ifndef STDLIB_H
#define STDLIB_H


#define NULL ((void*)0)




#define MEMPOOL_SZ (1024 * 1024)
static int MEMPOOL[MEMPOOL_SZ];
static uint32_t memoff = 0;

void* malloc(uint32_t size);
#endif
