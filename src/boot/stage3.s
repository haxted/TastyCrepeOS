[bits 32]
[extern bmain]
section .text
mov edi, 0xb8000

main:

        bprint welkom
        bprint NL
	




%include "src/boot/term.inc"

section .data
welkom: db "Welcome to HorrifyingBoot v0.1-0, for TastyCrepeOS", 0


