global KbdTakeInputPA
extern KbdTakeInputP

KbdTakeInputPA:
	pushad
	push ds
	push es
	push fs
	push gs
	push ss

	call KbdTakeInputP

	popad
	pop ds
	pop es
	pop fs
	pop gs
	pop ss
	iret
