bits 16
org 0x8000

cli
mov ax, 00h
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
	mov ah, 0x02
	mov cl, 2
	mov al, 4
	mov dh, 0
	mov ch, 0
	mov dl, 0x00
	mov bx, 0x9a00
	int 13h
	jc err
err:
	hlt

pmode:
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp dword 0x00:0x9a00

gdt_start:
	dd 0
	dd 0

 	dw 0xFFFF
        dw 0x0
        db 0x0
        db 0b10011110
        db 0b11001111
        db 0x0

        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10010010
        db 0b11001111
        db 0x0
gdt_end:


gdt_descriptor:
        dw gdt_end - gdt_start - 1
        dd gdt_start






times 512-($-$$) db 0

