global irq14_S
extern irq14

irq14_S:
    pushad
    push ds
    push fs
    push gs
    push es
    push ss

    call irq14

    pop ss
    pop es
    pop gs
    pop fs
    pop ds
    popad
    iret