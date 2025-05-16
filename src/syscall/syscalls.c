#include <syscalls.h>


void initsyscalls() {
	setIDTEntry(0x80, (uint32_t*)int80hstb, 0x8e);
}

void syscall(syscallFrame *frame) {
	switch(frame->edi) {
		case 0: kputs((const char*)frame->esi); break;
		case 1: clrscr(); break;
		case 2: clrscrC((rgb_t*)frame->esi); break;
		case 3: printr((char)frame->esi, (int)frame->edx, (int)frame->ecx, (rgb_t*)frame->ebx, (loc_t*)frame->eax); break;
		case 4: memcpyb((uint32_t*)frame->esi, (uint32_t*)frame->edx, frame->ecx); break;
		case 5: memcpyw((uint32_t*)frame->esi, (uint32_t*)frame->edx, frame->ecx); break;
		case 6: memcpyd((uint32_t*)frame->esi, (uint32_t*)frame->edx, frame->ecx); break; 
		case 7: inb((uint16_t)frame->esi); break;
		case 8: outb((uint16_t)frame->esi, (uint8_t)frame->edx); break;
		case 9: inw((uint16_t)frame->esi); break;
		case 10: outw((uint16_t)frame->esi, (uint16_t)frame->edx); break;
		case 11: ataFunc((ataParam_t*)frame->esi, (int)frame->edx);
		case 12: videoFunc((int)frame->esi, (videoParam_t*)frame->edx);
		case 13: kbdFunc((int)frame->esi);
		default: panic("No/unknown syscall"); break;
	}


}
