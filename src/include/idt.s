 global loadidt
 global gpfhandle
 extern gpfhandleC

 loadidt:
	mov eax, [esp+4]
	nop
	lidt [eax]
	sti
	ret

gpfhandle:
	pusha
	push ds
	push es
	push fs
	push gs
	push ss
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	cli
	call gpfhandleC
	sti
	popa
	pop ds
	pop es
	pop fs
	pop gs
	pop ss
	iret

