[bits 32]
[extern bmain]
section .text
global _start
mov edi, 0xb8000

_start:
        cli
        mov ax, 0x10
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov ss, ax
        mov sp, 0x8f00
        stis

        mov eax, [0x8428]
        push eax
        call bmain
        jmp $
	





section .data
welkom: db "Welcome to HorrifyingBoot v0.1.2, for TastyCrepeOS", 0


