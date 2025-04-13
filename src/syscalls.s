global systmcall
global int80hstb

extern kputs
extern kprintf

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
	
	cmp edi, 1
	je SystmPutStringF
	ret
SystmPutString:
	push esi
	call kputs
	pop esi
	ret
SystmPutStringF:
	push esi
	call kprintf
	pop esi
	ret
	

	
