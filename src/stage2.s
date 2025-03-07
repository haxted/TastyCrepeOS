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
jmp start

; WARNING: TRIPLE FAULTS AHEAD
gdt_start:
        dd 0x0
        dd 0x0
        dw 0xFFFF
        dw 0x0
        db 0x0
        db 0x00
        db 0x00
        db 0x00

        db 10011010b
	db 11001111b 

        db 0x0

        dw 0xFFFF
        dw 0x0
        db 0x0
        db 10010010b
        db 11001111b
        db 0x0

gdt_end:

gdt_descriptor:
        dw gdt_end - gdt_start - 1
        dd gdt_start
start:
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp dword 0x08:_pmode


[bits 32]
_pmode:
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	mov ebp, 0x100000
	mov esp, ebp
	in al, 0x92
	or al, 2
	out 0x92, al
	mov dword [0xB8000], 0x07690748
	
	
	jmp $

msg: db "Welcome to TastyCrepe!", 0
times 8192-($-$$) db 0

