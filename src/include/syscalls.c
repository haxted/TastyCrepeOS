#include <syscalls.h>


void initsyscalls() {
	setIDTEntry(0x80, (uint32_t)int80hstb, 0x8e);
}

void syscall(syscallFrame *frame) {
	switch(frame->edi) {
		case 0: kputs((const char*)frame->esi); break;
		case 1: kprintf((const char*)frame->esi); break;
		case 2: clrscr(); break;
		case 3: clrscrC((unsigned char)frame->esi); break;
		case 4: printr((char)frame->esi, (int)frame->edx, (int)frame->ecx, (unsigned char)frame->ebx); break;
		default: panic("No/unknown syscall"); break;
	}


}
