#include <fat32.h>

stackAllocator fatAlloc;
static uint8_t fatStack[512] /* lmao */ 

fat32Bootsect _fat32ReadBootsect() {
    fat32Bootsect bootsect;
    uint8_t* bootsectBuffer; 
    stackInit(&fatAlloc, fatStack, sizeof(fatStack));
    bootsectBuffer = malloc(&fatAlloc, 512);        // Allocate memory for the boot sector.
    uint32_t bufferAddr = (uint32_t)(uintptr_t)bootsectBuffer; // Get the buffer address to read the disk.
    ataReadDisk(0, 0xA0, 1, 0, bufferAddr); // Read.
    // Copy everything.
    bootsect = *(fat32Bootsect*)bufferAddr;

    if(bootsect.jump[0] != 0xEB /* jmp short */ || bootsect.jump[1] != (sizeof(fat32Bootsect) - 423) || bootsect.jump[2] != 0x90) {
        kputs("[FAT32] Invalid bootsector jump"); // Print error.
        free(&fatAlloc, 512);
        return; // Return to the caller.
    }
    
    free(&fatAlloc, 512);
    return bootsect;
}

void _fat32ReadRoot(sfde_t* out, int index) {
    fat32Bootsect bootsect = _fat32ReadBootsect();
    // TODO
}