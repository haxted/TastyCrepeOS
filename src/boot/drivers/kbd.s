global kbdst
extern kbdindbg

kbdst:
        pushad
        push ds
        push es
        push fs
        push gs
        push ss

        call kbdindbg

        popad
        pop ds
        pop es
        pop fs
        pop gs
        pop ss
        iret
