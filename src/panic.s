global panic
extern kprintn
extern kprintf
extern kputs


panic:
    lea eax, [msg]
    call kprintf

    lea eax, [esp+4]
    push eax
    call kputs

    lea eax, [eaxs]
    push eax
    call kprintf


    push eax
    call kprintn

    push 0
    call kputs

    lea eax, [ebxs]
    push eax
    call kprintf

    push ebx
    call kprintn
    
    push 0
    call kputs

    lea eax, [ecxs]
    push eax
    call kprintf

    push ecx
    call kprintn
    
    push 0
    call kputs

    lea eax, [edxs]
    push eax
    call kprintf

    push edx
    call kprintn

    push 0
    call kputs

    lea eax, [esis]
    push eax
    call kprintf

    push esi
    call kprintn

    push 0
    call kputs

    lea eax, [edis]
    push eax
    call kprintf

    push edi
    call kprintn

    push 0
    call kputs

    lea eax, [eflagsx]
    push eax
    call kprintf

    pushfd
    call kprintn

    push 0
    call kputs

    cli
    hlt
    jmp $-2



section .data

msg: db "Kernel panic: ", 0
eaxs: db "EAX: ", 0
ebxs: db "EBX: ", 0
ecxs: db "ECX: ", 0
edxs: db "EDX: ", 0
esis: db "ESI: ", 0
edis: db "EDI: ", 0
eflagsx: db "EFLAGS: ", 0