global jmpkrnl

jmpkrnl:
        mov eax, [esp+4]
        jmp eax
