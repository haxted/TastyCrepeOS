#include <syscalls.h>


void initsyscalls() {
	setIDTEntry(0x80, (uint32_t*)int80hstb, 0x8e);
}

void syscall(syscallFrame *frame) {
	switch(frame->edi) {
		case 0: kputs((const char*)frame->esi); break;
		case 1: kprintf((const char*)frame->esi); break;
		case 2: clrscr(); break;
		case 3: clrscrC((unsigned char)frame->esi); break;
		case 4: printr((char)frame->esi, (int)frame->edx, (int)frame->ecx, (unsigned char)frame->ebx); break;
		case 5: memcpyb((uint32_t*)frame->esi, (uint32_t*)frame->edx, frame->ecx); break;
		case 6: memcpyw((uint32_t*)frame->esi, (uint32_t*)frame->edx, frame->ecx); break;
		case 7: memcpyd((uint32_t*)frame->esi, (uint32_t*)frame->edx, frame->ecx); break; 
		case 8: inb((uint16_t)frame->esi); break;
		case 9: outb((uint16_t)frame->esi, (uint8_t)frame->edx);
		case 10: inw((uint16_t)frame->esi, (uint16_t)frame->edx);
		case 11: outw((uint16_t)frame->esi, (uint16_t)frame->edx);
		default: panic("No/unknown syscall"); break;
	}


}
