global irq14_S
extern irq14

irq14_S:
    pushad
    push ds
    push fs
    push gs
    push es
    push ss
    
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    call irq14

    pop ss
    pop es
    pop gs
    pop fs
    pop ds
    popad
    iret