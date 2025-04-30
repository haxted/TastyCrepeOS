[bits 32]
extern kmain
global _start
_start:
	mov eax, 0x0
	cpuid
	call kmain
	jmp $
