global KbdTakeInputPA
extern KbdTakeInput

KbdTakeInputPA:
	pushad
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

	call KbdTakeInput

	popad
	pop ds
	pop es
	pop fs
	pop gs
	pop ss
	iret
