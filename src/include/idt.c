
#include <idt.h>
#include <stdio.h>
static idtentry idt[IDT_SIZE];
idtptr idt_ptr;

void setIDTEntry(uint8_t index, void* handlr, uint8_t type) {
	puts("Setting IDT Entry");
	puts("\n");
	idtentry* desc = &idt[index];
	desc->offset1 = (uint32_t)handlr & 0xffff;
	desc->selector = 0x8;
	desc->type = type;
	desc->offset2 = (uint32_t)handlr >> 16;
	desc->zero = 0x0000000;
}

void initidt() {
	puts("HEY HEY HEY WE GONNA INIT THE IDT, IF THERES ANY PROBLEMS CONTACT rakoczijohnii@gmail.com");
	puts("\n");
	idt_ptr.base = (unsigned long)&idt[0];
	idt_ptr.limit = (uint16_t)sizeof(idtentry) * IDT_SIZE - 1;
	

	for(int i = 0; i < 32; ++i){
		setIDTEntry(i, 0, 0x8e);
	}
	loadidt(&idt_ptr);
}	
