#include <string.h>

void memcpyb(void* dest, const void* src, int sz) {
    unsigned char* d = (unsigned char*)dest;
    unsigned char* s = (unsigned char*)src;
    for(int i = 0; i < sz; i++) {
        d[i] = s[i];
    }
}

void memcpyw(void* dest, const void* src, int sz) {
    uint16_t* d = (uint16_t*)dest;
    uint16_t* s = (uint16_t*)src;
    for(int i = 0; i < sz; i++) { 
        d[i] = s[i];
    }
}

void memcpyd(void* dest, const void* src, int sz) {
    uint32_t* d = (uint32_t*)dest;
    uint32_t* s = (uint32_t*)src;
    for(int i = 0; i < sz; i++) {
        d[i] = s[i];
    }
}