
#include <idt.h>
#include <stdio.h>
#include <kernel.h>

static idtentry idt[IDT_SIZE];
idtptr idt_ptr;

void setIDTEntry(uint8_t index, uint32_t* handlr, uint8_t type) {
	kputs("Setting IDT Entry");
	idtentry* desc = &idt[index];
	desc->offset1 = (uint32_t)handlr & 0xffff;
	desc->selector = 0x8;
	desc->type = type;
	desc->offset2 = (uint32_t)handlr >> 16;
	desc->zero = 0x0000000;
}

void initidt() {
	kputs("Initializing IDT...");
	idt_ptr.base = (unsigned long)&idt[0];
	idt_ptr.limit = (uint16_t)sizeof(idtentry) * IDT_SIZE - 1;
	

	for(int i = 0; i < IDT_SIZE; ++i){
		setIDTEntry(i, 0, 0x8e);
	}
	setIDTEntry(0x0d, (uint32_t*)gpfhandle, 0x8f);
	loadidt(&idt_ptr);
}

void gpfhandleC() {
	panic("General protection fault!");
}
