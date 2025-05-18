#include <ata.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ATTR_READONLY 1
#define ATTR_HIDDEN 2
#define ATTR_SYS 4
#define ATTR_DIR 16

typedef struct {
    uint8_t jump[3];
    char oem[8];
    uint16_t bytesPerSector;
    uint8_t sectorsPerCluster;
    uint16_t reservedSectors;
    uint8_t numberOfFATs;
    uint16_t rootDirectoryEntries;
    uint16_t numberOfSectors;
    uint8_t mediaType;
    uint16_t thisIsUselessDontMindIt;
    uint16_t sectorsPerTrack;
    uint16_t numberOfHeads;
    uint32_t numberOfHiddenSects;
    uint32_t largeSectorCount;
    // EBR starts here.
    uint32_t sectorsPerFAT;
    uint16_t flags;
    uint16_t FATVersion;
    uint32_t rootDirCluster;
    uint16_t FSinfoSectorNum;
    uint16_t backupSector;
    uint8_t ebrReserved[12];
    uint8_t driveNumber;
    uint8_t NTSlop;
    uint8_t signature;
    uint32_t volumeID;
    char volumeLabel[11];
    char identifier[8];
    uint8_t code[420];
    uint16_t biosSignature;
} __attribute__((packed)) fat32Bootsect;

typedef struct {
    uint32_t FSinfoSig;
    uint8_t bloat[480];
    uint32_t FSinfoSig2;
    uint32_t freeClusters;
    uint32_t availableClusterNumber;
    uint8_t moreBloat[12];
    uint32_t FSinfoSig3;
} __attribute__((packed)) fsinfoStruct;

typedef struct {
    char filename[8];
    char ext[3];
    uint8_t attr;
    uint8_t reserved;
    uint8_t creationth;
    uint16_t creationt;
    uint16_t creationdate
    uint16_t lastaccessdate;
    uint16_t firstclusterhigh;
    uint16_t writetime;
    uint16_t writedate;
    uint16_t firstclusterlow;
    uint32_t filesz;
} __attribute__((packed)) sfde_t;

int fat32Read(char filename[8], char ext[3], void* buffer);
void _fat32ReadFAT();
void _fat32ReadRoot();
void _fat32ReadBootsect(sfde_t* out);