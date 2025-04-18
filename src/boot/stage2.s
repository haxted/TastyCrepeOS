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
; struc elfhdr
;	e_ident: db 16 dup(0)
;	e_type: resb 2
;	e_machine: resb 2
;	e_version: resd 1
;	e_entry: resd 1
;	e_phoff: resd 1
;	e_shoff: resd 1
;	e_flags: resd 1
;	e_ehsize: resb 2
;	e_phentsize: resb 2
;	e_phnum: resb 2
;	e_shentsize: resb 2
;	e_shnum: resb 2
;	e_shstrndx: resb 2
;endstruc


jmp _start
elfR:
	cmp byte [bx],  0x7f
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

	
.done: pop eax





	





	







_start:
	mov ah, 0x02
	mov cl, 3
	mov al, 4
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

pmode:
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp dword 0x08:relcs

gdt_start:
	dd 0
	dd 0

 	dw 0xFFFF
        dw 0x0
        db 0x0
        db 0b10011110
        db 0b11001111
        db 0x0

        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10010010
        db 0b11001111
        db 0x0
gdt_end:


gdt_descriptor:
        dw gdt_end - gdt_start - 1
        dd gdt_start



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

	jmp edx


times 512-($-$$) db 0

