org 0x7c00
bits 16

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
	mov al, 8
	mov ch, 0
	mov cl, 2
	mov dh, 0
	mov dl, 0x00
	mov bx, 0x8000
	int 13h
	jc err
	jmp 0x8000
print:
	lodsb
	cmp al, 0
	je done
	mov ah, 0eh
	int 10h
	jmp print
done:
	ret
err:
	mov si, errormsg
	call print
	mov ah, 0x01
	int 16h
	cmp al, 0
	jz read
	; haha get your floppies broken

errormsg: db "Error! Press any key to restart", 0
times 510-($-$$) db 0
dw 0xaa55
