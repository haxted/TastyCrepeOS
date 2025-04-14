global systmcall
global int80hstb

extern kputs
extern kprintf
extern clrscr
extern clrscrC
extern kputc
extern printr

int80hstb:
	pushad
	push ds
	push es
	push gs
	push fs
	push ss

	call systmcall

	popad
	pop ds
	pop fs
	pop es
	pop gs
	pop ss
	iret

systmcall:
	cmp edi, 0
	je $+2			; SystmPutString - puts in C
	call SystmPutString
	
	cmp edi, 1
	je $+2
	call SystmPutStringF

	cmp edi, 2
	je $+2
	call SystmClrScr

	cmp edi, 3
	je $+2

	call SystmClrScrC

	cmp edi, 4
	je $+2
	
	call SystmPutStringR

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
SystmClrScr:
	call clrscr
	ret
SystmClrScrC:
	push esi
	call clrscrC
	pop esi
	ret
SystmPutChar:
	push esi
	push edx
	call kputc
	pop esi
	pop edx
	ret

SystmPutStringR:
	push esi
	push edx
	push ecx
	push ebx
	call printr
	pop esi
	pop edx
	pop ecx
	pop ebx
	ret

	
