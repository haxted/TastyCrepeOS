#include "../include/ata.hxx"
using namespace Io;

namespace Disk {
bool __DISK_READ;
bool __DISK_WRITE;
unsigned int* __MEMLOCATION;
int __SECTORS;

void ata_init() {
  setEntry(14, (uint32_t*)atas, 0x8E);
}
void irq14handler() {
  while(inb(ATA_CMD) & 0x80);
  if(__DISK_READ) {
  for(int i = 0; i < __SECTORS * 512; i++) {
    uint8_t lb = inb(ATA_DATA);
    uint8_t hb = inb(ATA_DATA);
    uint16_t w = (hb << 8) | lb;

    __MEMLOCATION[i] = w;
    
  }
  }
  outb(0x20, 0x20);
}
  
  int ata_rdisk(int lba, int sects, unsigned int mem) {
    __MEMLOCATION  = (unsigned int*)mem;
    __DISK_READ = true;
    __SECTORS = sects;
    while(inb(ATA_CMD) & 0x80);
    if(inb(ATA_CMD) & 0x40) {
    outb(ATA_LL, lba & 0xff);
    outb(ATA_LM, (lba >> 8) & 0xff);
    outb(ATA_LH, (lba >> 16) & 0xff);
    outb(ATA_DH, 0xE0 | ((lba >> 24) & 0x0F));
    outb(ATA_SCT, sects);
    outb(ATA_CMD, 0x20);
    } else if(inb(ATA_CMD) & 1) {
      return 1;
    }
    return 0;
  }
    
  

  
  
  

};   // namespace Disk
