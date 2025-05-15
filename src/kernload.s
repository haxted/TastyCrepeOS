[bits 32]
extern kmain
global _start
_start:
	mov eax, 0x0
	cpuid
	mov edi, [0x8428]
	push edi
	push edx
	push ecx
	push ebx
	call kmain
	jmp $
