CC = clang
LD = ld.lld
KERNEL = build/kernel.elf
CFLAGS = -nostdlib -c -Isrc/include  -Wall -Wextra -Werror -fno-pie -fno-pic  -ffreestanding  -fno-stack-protector  -fno-strict-aliasing --target=i686-elf -g -fno-omit-frame-pointer -std=c23 -fno-builtin -mno-red-zone  -fno-exceptions -fno-rtti 


all:
	mkdir build
	$(CC) $(CFLAGS) src/video/stdio.c -o build/stdio.o
	$(CC) $(CFLAGS) src/io/io.c -o build/io.o
	$(CC) $(CFLAGS) src/memory/stdlib.c -o build/stdlib.o
	$(CC) $(CFLAGS) src/include/idt.c -o build/idt.o
	$(CC) $(CFLAGS) src/kernel.c -o build/kernel.o
	$(CC) $(CFLAGS) src/syscall/syscalls.c -o build/syscalls.o
	$(CC) $(CFLAGS) src/memory/string.c -o build/string.o
	$(CC) $(CFLAGS) src/drivers/disk/ata.c - o build/ata.o
	$(CC) $(CFLAGS) src/drivers/kbd/kbd.c - o build/kbd.o
	nasm -felf32 -g src/interrupts/idt.s -o build/idt.s.o
	nasm -felf32 -g src/kernload.s -o build/kernload.o
	nasm -felf32 -g src/syscall/syscalls.s -o build/syscalls.s.o
	nasm -felf32 -g src/panic.s -o build/panic.o
	nasm -felf32 -g src/disk/ata.s -o build/ata.s.o
	nasm -felf32 -g src/kbd/kbd.s -o build/kbd.s.o

	$(LD) -Tlinker.ld -o $(KERNEL) build/*.o -v -V -z noexecstack 
clean:
	rmdir /s /q build