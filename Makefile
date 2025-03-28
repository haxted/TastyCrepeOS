CC = clang
LD = ld.gold
CFLAGS = -nostdlib -c -Isrc/include --target=i686-elf -Wall -Wextra -Werror -fno-pie -fno-pic


all:
	mkdir -p build/
	$(CC) $(CFLAGS) src/include/stdio.c -o build/stdio.o
	$(CC) $(CFLAGS) src/include/io.c -o build/io.o
	$(CC) $(CFLAGS) src/include/stdlib.c -o build/stdlib.o
	$(CC) $(CFLAGS) src/include/idt.c -o build/idt.o
	$(CC) $(CFLAGS) src/kernel.c -o build/kernel.o
	nasm -felf32 src/include/idt.s -o build/idt.s.o
