#ifndef _IDT_HPP
#define _IDT_HPP
#define IDT_SZ 256
#include <stdint.h>
#include "term.hxx"
typedef struct {
  uint16_t offset1;
  uint16_t selector;
  uint8_t zer0;
  uint8_t type;
  uint16_t offset2;
} __attribute__((packed)) IDTEntry;

typedef struct {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed)) IDTPtr;

extern "C" {
void initIDT();
void setEntry(unsigned int index, void* handler, int type);
}
#endif
