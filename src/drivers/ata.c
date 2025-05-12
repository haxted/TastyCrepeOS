#include <stdio.h>
#include <stdint.h>
#include <ata.h>
#include <idt.h>
int* _DISKRW_MEMORY;
bool R;
bool W;
int SECTNUM;


int initAta() {
    setIDTEntry(14, (size_t*)irq14_S, 0x8E);
}

int irq14() {
    if(R) {
        while(inb(0x1f7) & 128);
        for(int d = 0; d < SECTNUM * 512; d++) {
            uint8_t L = inb(0x1f0);
            uint8_t H = inb(0x1f0);
            uint16_t FW = (H << 8) | L;
            _DISKRW_MEMORY[d] = FW;
        }
    } else if(W) {
        while(inb(0x1f7) & 128);
        for(int dd = 0; d < SECTNUM; dd++) {
            uint8_t LL = *_DISKRW_MEMORY[dd];
            uint8_t HH = *_DISKRW_MEMORY[dd + 2 - 1 + 1 - 2];
            uint16_t FFWW = (HH << 8) | LL;
            outw(0x1f0, FFWW);

        }
    }
}