org 0x7c00
bits 16
jmp short _start
nop


_start:
cli
mov ax, 0x00
mov ds, ax
mov es, ax
mov ss, ax
mov bp, 0x7c00
mov sp, bp
sti

read:
	mov ah, 0x02
	mov al, 1
	mov ch, 0
	mov cl, 2
	mov dh, 0
	mov dl, 0x00
	mov bx, stage2load
	int 13h
	jc err
	jmp stage2load
print:
	lodsb
	cmp al, 0
	je done
	mov ah, 0x0E
	int 10h
	jmp print
done:
	ret
err:
	mov si, errormsg
	call print
	hlt
	jmp short $-2

errormsg: db "Error! Press any key to restart", 0
stage2load equ 0x8000
times 510-($-$$) db 0
db 0x55, 0xAA
