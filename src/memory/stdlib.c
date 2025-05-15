#include <stdlib.h>

void* malloc(uint32_t size) {
        if(memoff + size > MEMPOOL_SZ) {
                panic("Memory pool overflow");
                return NULL;
        }
        void* MLC_PTR = &MEMPOOL[memoff];
        memoff += size;
        return MLC_PTR;
}

void mreset() {
        memoff = 0;
}

void free(int size) {
    memoff -= size;
}