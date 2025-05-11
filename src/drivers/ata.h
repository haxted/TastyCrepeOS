#ifndef ATA_H
#define ATA_H
#include <stdint.h>
#include <io.h>
#include <kernel.h>

int initAta();
int irq14();
extern void irq14_S();

int ataReadDisk(int bus, int drive, int sect, int lba, size_t mem); // DEVNOTES: esi, edx, ecx, ebx, eax
int ataWriteDisk(int bus, int drive, int sect, int lba, size_t mem);
int ataFormatZ(int bus, int drive);
bool ataDriveExists(int bus, int drive);


#endif

