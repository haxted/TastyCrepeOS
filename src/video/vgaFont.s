[bits 32]
global _setupVGA
global _restore

_setupVGA:
    mov dx, 0x03ce
    mov ax, 5
    out dx, ax
    mov ax, 0x0406
    out dx, ax
    mov ax, 0x0604
    out dx, ax
    ret
_restore:
    mov	ax, 0x0302
	out	dx, ax
	mov	ax, 0x0204
	out	dx, ax
	mov	dx, 0x03ce
	mov	ax, 0x1005
	out	dx, ax
	mov	ax, 0x0E06
	out	dx, ax
    ret
