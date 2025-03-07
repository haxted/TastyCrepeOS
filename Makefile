CC = tcc
LD = ld.gold
CFLAGS = -nostdlib -c  -m32

all:	
	nasm -f bin src/kernel.s -o build/stage2.bin 
	nasm -f bin src/stage1.s -o build/stage1.bin
	dd if=/dev/zero of=NewFlop.img bs=512 count=2880
	dd if=build/stage1.bin of=NewFlop.img seek=0 bs=512 conv=notrunc
	dd if=build/stage2.bin of=NewFlop.img seek=2 bs=512 conv=notrunc
