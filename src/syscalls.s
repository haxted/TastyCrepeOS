extern syscall
global int80hstb


int80hstb:
	push ds
	push es
	push gs
	push fs
	push ss
	mov eax, [esp+20]
	push eax
	pushad

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax


	call syscall

	popad
	pop ds
	pop fs
	pop es
	pop gs
	pop ss
	iret


	
