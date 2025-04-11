
#ifndef IDT_H
#define IDT_H
#include <stdint.h>
#include <io.h>

typedef struct InterruptDescriptor {
	uint16_t offset1;
	uint16_t selector;
	uint8_t zero;
	uint8_t type;
	uint16_t offset2;
} __attribute__((packed)) idtentry;

typedef struct idtptr {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed)) idtptr;

#define IDT_SIZE 256

extern void gpfhandle();

void setIDTEntry(uint8_t index, void* handlr, uint8_t type);

extern void loadidt(idtptr* idt_ptr);
void initidt();

#endif

