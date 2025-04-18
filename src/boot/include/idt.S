global lidt

lidt:
        lea eax, [esp+4]
        lidt [eax]
        ret
