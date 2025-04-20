#pragma once
#include <cstdint>


typedef uint32_t ElfAddr;
typedef uint16_t ElfHalf;
typedef int32_t ElfSword;
typedef uint32_t ElfWord;
typedef uint32_t ElfOff;

typedef struct {
  unsigned char e_ident[16];
  ElfHalf e_type;
  ElfHalf e_machine;
  ElfAddr e_entry;
  ElfOff e_phoff;
  ElfOff e_shoff;
  ElfWord e_flags;
  ElfHalf eh_size;
  ElfHalf e_phentsize;
  ElfHalf e_phnum;
  ElfHalf e_shentsize;
  ElfHalf e_shnum;
  ElfHalf e_shstrndx;
} __attribute__((packed)) ElfHdr;

