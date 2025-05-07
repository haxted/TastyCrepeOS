global memcpyb
global memcpyw
global memcpyd

memcpyb:
    mov edi, 4
    lea esi, [esp+4]
    lea edx, [esp+8]
    mov ecx, [esp+8]
    int 0x80
    ret
memcpyw:
    mov edi, 5
    lea esi, [esp+4]
    lea edx, [esp+8]
    mov ecx, [esp+8]
    int 0x80
    ret
memcpyd:
    mov edi, 6
    lea esi, [esp+4]
    lea edx, [esp+8]
    mov ecx, [esp+8]
    int 0x80
    ret