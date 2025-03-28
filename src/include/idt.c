#include <idt.h>

void setIDTEntry(int index, uint32_t handler, uint16_t selector, uint8_t type) {
	idt[index].offset1 = handler & 0xffff;
	idt[index].selector = selector;
	idt[index].zero = 0;
	idt[index].offset2 = (handler >> 16) & 0xffff;
	idt[index].type = type;
}

void initidt() {
	idt_ptr.limit = sizeof(idt) - 1;
	idt_ptr.base = (uint32_t)&idt;
	

	for(int i = 0; i < IDT_SIZE; i++){
		setIDTEntry(i, 0, 0, 0);
	}
	loadidt(&idt_ptr);
}
