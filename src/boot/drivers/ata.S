[bits 32]
global atas
extern irq14handler

atas:
        pushad
        push ds
        push es
        push fs
        push gs
        push ss

        call irq14handler

        popad
        pop ds
        pop es
        ppp fs
        pop gs
        pop ss
        iret
