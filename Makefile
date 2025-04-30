CC = clang
LD = ld.lld
CFLAGS = -nostdlib -c -Isrc/include  -Wall -Wextra -Werror -fno-pie -fno-pic  -ffreestanding  -fno-stack-protector  -fno-strict-aliasing --target=i686-elf -g -fno-omit-frame-pointer -std=c23 -fno-builtin -mno-red-zone  -fno-exceptions -fno-rtti 


all:
	mkdir -p build/
	$(CC) $(CFLAGS) src/include/stdio.c -o build/stdio.o
	$(CC) $(CFLAGS) src/include/io.c -o build/io.o
	$(CC) $(CFLAGS) src/include/stdlib.c -o build/stdlib.o
	$(CC) $(CFLAGS) src/include/idt.c -o build/idt.o
	$(CC) $(CFLAGS) src/kernel.c -o build/kernel.o
	$(CC) $(CFLAGS) src/include/syscalls.c -o build/syscalls.o
	$(CC) $(CFLAGS) src/include/string.c -o build/string.o
	nasm -felf32 -g src/include/idt.s -o build/idt.s.o
	nasm -felf32 -g src/kernload.s -o build/kernload.o
	nasm -felf32 -g src/syscalls.s -o build/syscalls.s.o
	$(LD) -Tlinker.ld -o build/kernel.elf build/kernload.o build/kernel.o build/stdio.o build/stdlib.o build/io.o build/idt.o build/idt.s.o build/syscalls.o build/syscalls.s.o -nostdlib -z noexecstack 
