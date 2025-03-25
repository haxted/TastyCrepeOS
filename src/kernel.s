bits 16
extern kmain


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
	jmp dword 0x08:_kernel_start


gdt_start:
	dd 0x0
	dd 0x0
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




[bits 32]
_kernel_start:
	mov ax, 0x10
	mov es, ax
	mov ds, ax
	mov gs, ax
	mov fs, ax
	mov ss, ax
	mov ebp, 0x9a00
	mov ebp, esp
	call kmain

	jmp $
	
	
