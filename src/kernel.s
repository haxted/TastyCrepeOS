org 0x8000
bits 16

cli
mov ax, 0x00
mov ds, ax
mov es, ax
mov ss, ax
mov bp, 0x8000
mov sp, bp
sti
mov ah, 0x00
mov al, 0x03
int 0x10
jmp _start

_start:
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp dword CODESEG:_kernel_start


gdt_start:
	dd 0x0
	dd 0x0
gdt_code:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 0b10011110
	db 0b11110011
