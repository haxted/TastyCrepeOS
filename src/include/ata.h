#ifndef ATA_H
#define ATA_H
#include <stdint.h>
#include <io.h>
#include <kernel.h>
#include <stdio.h>

void initAta();
int irq14();
extern void irq14_S();
typedef struct {
    int bus;
    int drive;
    int sect;
    int lba;
    int mem;
} __attribute__((packed)) ataParam_t;

int ataReadDisk(int bus, int drive, int sect, int lba, int mem); // DEVNOTES: esi, edx, ecx, ebx, eax
int ataWriteDisk(int bus, int drive, int sect, int lba, int mem);
int ataFormatZ(int bus, int drive);
bool ataDriveExists(int bus, int drive);
void ataFunc(ataParam_t *param, int func);


#endif

