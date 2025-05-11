global switchtsk

switchtsk:
    pushad ; 32 bytes
    pushfd ; 4 bytes, 36 bytes total pushed. args start at esp+40 (i think)
    
    ; DOES NOT DO EIP, FIXLATER
    mov [esp+40], eax
    mov [esp+44], ebx
    mov [esp+48], ecx
    mov [esp+52], edx
    mov [esp+56], esi
    mov [esp+60], edi
    mov [esp+64], esp
    mov [esp+68], ebp
    mov eax, [esp+36]
    mov [esp+76], eax ; pro move


    xchg ax, ax
    ; time to get the new state!!! if im not fucking everything up
    ; preeeetty sure the new state is at esp+76
    ; EDIT: i was wrong its at esp+80

    mov eax, [esp+80]
    mov ebx, [esp+84]
    mov ecx, [esp+88]
    mov edx, [esp+92]
    mov esi, [esp+96]
    mov edi, [esp+100]
    mov esp, [esp+104]
    mov ebp, [esp+108]
    ; done.. i think :dumdum:
    ret
global getEFLAGS
global getESP
global getEBP
getEFLAGS:
    pushfd
    mov eax, [esp+4]
    ret
getESP:
    mov eax, esp
    ret
getEBP:
    mov eax, ebp
    ret

    