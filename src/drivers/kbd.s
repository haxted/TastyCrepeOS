global KbdTakeInputPA
extern KbdTakeInputP

KbdTakeInputPA:
	pusha
	push ds
	push es
	push fs
	push gs
	push ss

	call KbdTakeInputP

	popa
	pop ds
	pop es
	pop fs
	pop gs
	pop ss
	iret
