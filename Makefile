CC = cc
LD = ld.gold
CFLAGS = -nostdlib -c -Isrc/include  -Wall -Wextra -Werror -fno-pie -fno-pic  -ffreestanding -g  -fno-stack-protector  -fno-strict-aliasing --target=i686-elf -fno-omit-frame-pointer


all:
	mkdir -p build/
	$(CC) $(CFLAGS) src/include/stdio.c -o build/stdio.o
	$(CC) $(CFLAGS) src/include/io.c -o build/io.o
	$(CC) $(CFLAGS) src/include/stdlib.c -o build/stdlib.o
	$(CC) $(CFLAGS) src/include/idt.c -o build/idt.o
	$(CC) $(CFLAGS) src/kernel.c -o build/kernel.o
	nasm -felf32 src/include/idt.s -o build/idt.s.o
	nasm -felf32 src/kernload.s -o build/kernload.o
	$(LD) -Tlinker.ld -o build/kernel.elf build/kernload.o build/kernel.o build/stdio.o build/stdlib.o build/io.o build/idt.o build/idt.s.o -nostdlib 
