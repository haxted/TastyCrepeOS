[bits 32]
[org 0x9a00]

mov ax, 0x10
mov ds, ax
mov es, ax
mov ss, ax
mov fs, ax
mov gs, ax
mov ebp, 0x9a00
mov esp, ebp

jmp start

start:
	call loadKernel
	call parseELF
	jmp 0xDEADC0DE:0xDEADBEEF


; THIS IS NOT FINISHED
; UNDER CONSTRUCTION

initDisk0Motor:
	mov dx, 0x3f2
	inb al, dx
	or al, 16
	outb dx, al

	

	












times 2048-($-$$) db 0	


