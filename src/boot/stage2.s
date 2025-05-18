bits 16
org 0x8000

cli
mov ax, 00h
mov ds, ax
mov es, ax
mov ss, ax
mov bp, 0x8000
mov sp, bp
sti

mov ah, 0x00
mov al, 0x03
int 0x10

jmp _start
elfR:
	cmp dword [bx], 0x464C457F ; 7F 45 4C 46 (7F "ELF")
	jne err
	je isELF

isELF:
	add bx, 16
	cmp word [bx], 2
	jne err
	add bx, 2
	cmp word [bx], 3
	jne err

	add bx, 2
	cmp word [bx], 1
	jne err

	  mov dword eax, [bx]

	add bx, 4
	 mov dword ecx, [bx]

	 mov edx, eax
	 add edx, ecx ; edx now contains the location of phdr

	 mov ebx, 0x9a00
	 add ebx, 0x2a
	 push eax
	  mov word ax, [ebx]
	 sub ebx, 4
.loop:
	cmp ax, 0
	je .done

	  mov dword esi, [edx]
	 add edx, 4

	  mov dword edi, [edx]
	 add edx, 8




	  mov dword ecx, [edx]
	 mov edx, eax

	 sub edx, 12
	

	rep movsb

	dec ax
	
	jmp .loop

	
.done:
	pop eax
	mov ax, 0x4f02
	mov bx, 0x11b
	int 0x10

	mov ax, 0x4f02
	mov bx, 0x411b
	int 0x10

	mov ax, 0x4f01
	mov cx, 0x11b
	mov di, 0x1000
	int 0x10
	mov ecx, [di+0x28]

	mov [0x8400], ecx

	jmp pmode






_start:
	mov si, chs
	call print
	mov ah, 0x00
	int 16h
	call sg2_804617

	
	mov ah, 0x02
	mov cl, 4
	mov al, 60
	mov dh, 0
	mov ch, 0
	mov dl, 0x00
	mov bx, 0x9a00
	int 13h
	jc err
	jnc elfR
err:
	hlt
	jmp err
sg2_804617:
	mov ax, sg2_6648
	xchg ax, si
	call print
	mov ah, 0x00
	int 16h
	cmp al, 'c'
	je .sg2_489

	cmp al, 'g'
	je .sg2_C4
.sg2_489: ret
.sg2_C4:
	mov si, sg2_TON618
	call print
	mov ah, 00h
	int 16h
	pop bx
	cmp al, 'H'
	je .ok
	jne .lost
.ok:
	mov si, sg2_LOSER
	call print
	ret
.lost:
	mov si, sg2_IDIOT
	call print
	int 16h
	ret
sg2_IDIOT: db "you lost!", 0
sg2_LOSER: db "you won!", 0
sg2_6648:  db "what you want", 0b00000000000000000
sg2_badword:   db "this is just to annoy you", 0
sg2_TON618: db "the completely random guessing game: ", 0
	
	
	
print:
	lodsb
	cmp al, 0
	je .done
	mov ah, 0x0E
	int 10h
	jmp print
.done: ret

pmode:
	cli
	lea eax, [gdt_descriptor]
	lgdt [eax]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp dword 0x08:relcs

gdt_start:
	dd 0
	dd 0

 	dw 0xFFFF
        dw 0
        db 0
        db 0b10011110
        db 0b11001111
        db 0

        dw 0xffff
        dw 0
        db 0
        db 0b10010010
        db 0b11001111
        db 0x0
gdt_end:


gdt_descriptor:
        dw gdt_end - gdt_start - 1
        dd gdt_start

chs: db "Press C to continue booting, press G to start some games and stuff", 0



[bits 32]
relcs:
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	mov esp, 0x8fff
	in al, 0x92
	or al, 2
	out 0x92, al
	xchg al, al
	mov al, al
	nop

	jmp ebx


times 1024-($-$$) db 0

