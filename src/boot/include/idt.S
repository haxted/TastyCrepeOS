global lidt

lidt:
        lea eax, [esp+4]
        lidt [eax]
        sti
        ret
