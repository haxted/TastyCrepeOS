bits 16
org 0x8000

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
int 10h
jmp _start

_start:
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp CODESEG:_ProtectedMode
	jmp $

gdt_start:

gdt_null:
	dd 0x0
	dd 0x0
gdt_code:
	dw 0xffff
	dw 0x0
	db 0x0
	db 0x9a
	db 0xcf
	db 0x0
gdt_data:
	dw 0xffff
	dw 0x0
	db 0x0
	db 0x92
	db 0xcf
	db 0x0

gdt_end:
	
gdt_descriptor:
	dw gdt_end - gdt_start - 1
	dd gdt_start
CODESEG equ gdt_code - gdt_start - 1
DATASEG equ gdt_data - gdt_start - 1

[bits 32]
_ProtectedMode:
	mov ax, DATASEG
	mov es, ax
	mov ds, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	mov ebp, 0x9c00
	mov esp, ebp
	
	jmp $




times 16384-($-$$) db 0
