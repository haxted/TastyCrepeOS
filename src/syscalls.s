global systmcall
global int80hstb

extern puts

int80hstb:
	pusha
	push ds
	push es
	push gs
	push fs
	push ss

	call systmcall

	popa
	pop ds
	pop fs
	pop es
	pop gs
	pop ss
	iret

systmcall:
	cmp edi, 0		; SystmPutString - puts in C
	je SystmPutString
	ret
SystmPutString:
	push esi
	call puts
	pop esi
	ret
	

	
