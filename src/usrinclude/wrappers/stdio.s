global writes
global writef
global writer
global clrs
global clrscol

writes:
    mov edi, 0
    lea esi, [esp+4]
    int 0x80
    ret
writef:
    mov edi, 1
    lea esi, [esp+4]
    int 0x80
    ret
writer:
    mov edi, 4
    mov esi, [esp+4]
    mov edx, [esp+8]
    mov ecx, [esp+12]
    mov ebx, [esp+16]
    int 0x80
    ret
clrs:
    mov edi, 2
    int 0x80
    ret
clrscol:
    mov edi, 2
    mov esi, [esp+4]
    int 0x80
    ret
