[bits 32]
[extern bmain]
section .text
global _start
mov edi, 0xb8000

_start:

        mov eax, [0x8400]
        push eax
        call bmain
        jmp $
	





section .data
welkom: db "Welcome to HorrifyingBoot v0.1-0, for TastyCrepeOS", 0


