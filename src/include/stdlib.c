#include <stdlib.h>

void* malloc(uint32_t size) {
        if(memoff + size > MEMPOOL) {
                panic("Memory pool overflow");
                return NULL;
        }
        void* MLC_PTR = &MEMPOOL[memoff];
        memoff += size;
        return MLC_PTR;
}
