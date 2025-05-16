global writes
global writer
global clrs
global clrscol
global videofunc

writes:
    mov edi, 0
    lea esi, [esp+4]
    int 0x80
    ret
writer:
    mov edi, 3
    mov esi, [esp+4]
    mov edx, [esp+8]
    mov ecx, [esp+12]
    lea ebx, [esp+16]
    lea eax, [esp+20]
    int 0x80
    ret
clrs:
    mov edi, 1
    int 0x80
    ret
clrscol:
    mov edi, 2
    lea esi, [esp+4]
    int 0x80
    ret
videofunc:
    mov edi, 12
    mov esi, [esp+4]
    lea edx, [esp+8]
    int 0x80
    ret
global kbdfunc
kbdfunc:
    mov edi, 13
    mov esi, [esp+4]
    int 0x80
    ret
