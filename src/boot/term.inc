[bits 32]
%define NL 0x0A, 0x0D

%macro bprint 1
call print_%line
print_%line:
  mov esi, %1
  lodsb
  test al, al
  jz .done
  mov ah, 0x07
  mov word [edi], ax
  add edi, 2
  jmp print_%line
.done_%line:
  ret
%endmacro
