global loadidt

loadidt:
	mov eax, [esp+4]
	lidt [eax]
	ret
