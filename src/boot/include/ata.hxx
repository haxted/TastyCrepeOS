#ifndef _ATA_HPP
#define _ATA_HPP
#include "idt.hxx"
#include "io.hxx"

#define ATA_DATA 0x1f0
#define ATA_M1 0x1f1
#define ATA_SCT 0x1f2
#define ATA_LL 0x1f3
#define ATA_LM 0x1f4
#define ATA_LH 0x1f5
#define ATA_DH 0x1f6
#define ATA_CMD 0x1f7
#define ATA_CR 0x3f6

#define ATAS_DATA 0x170
#define ATAS_M1 0x171
#define ATAS_SCT 0x172
#define ATAS_LL 0x173
#define ATAS_LM 0x174
#define ATAS_LH 0x175
#define ATAS_DH 0x176
#define ATAS_CMD 0x177
#define ATAS_CR 0x376

#define ATA3_DATA 0x1E8
#define ATA3_M1 0x1e9
#define ATA3_SCT 0x1ea
#define ATA3_LL 0x1eb
#define ATA3_LM 0x1ec
#define ATA3_LH 0x1ed
#define ATA3_DH 0x1ee
#define ATA3_CMD 0x1ef
#define ATA3_CR 0x3e6

#define ATA4_DATA 0x168
#define ATA4_M1 0x169
#define ATA4_SCT 0x16a
#define ATA4_LL 0x16b
#define ATA4_LM 0x16c
#define ATA4_LH 0x16d
#define ATA4_DH 0x16e
#define ATA4_CMD 0x16f
#define ATA4_CR 0x366

namespace Disk {
  void ata_rdisk(int lba, int sects, unsigned int mem);
  void ata_reset();
  void ata_wdisk(unsigned char drive, int lba, int sects, unsigned int mem);
  void ata_init();
  extern void atas();
};

#endif

