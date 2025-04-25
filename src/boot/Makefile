CC        := clang++
CFLAGS    := -nostdlib -Isrc/include -Wall -Wextra  \
             -fno-pie -fno-pic -ffreestanding -fno-stack-protector \
             -fno-strict-aliasing --target=i686-elf -g \
             -fno-omit-frame-pointer  -fno-builtin \
             -mno-red-zone -fno-exceptions  -fno-rtti -D_LIBCPP_HAS_NO_THREADS \
			 -nodefaultlibs -nostartfiles -mno-sse -mno-avx -mno-sse2 \
			 -mno-sse3 -mno-mmx -mno-fma

BUILD_DIR := build
SRCS      := $(wildcard *.cxx) $(wildcard drivers/*.cxx) $(wildcard include/*.cxx)
OBJS      := $(SRCS:%.cxx=$(BUILD_DIR)/%.o)

.PHONY: all clean
all: $(OBJS) asm

$(BUILD_DIR)/%.o: %.cxx
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
asm:
	nasm -felf32 drivers/ata.S -o build/ata.s.o
	nasm -felf32 include/idt.S -o build/idt.s.o
	nasm -fbin   ./stage1.s -o build/stage1.bin
	nasm -fbin   ./stage2.s -o build/stage2.bin
	nasm -felf32   ./stage3.s -o build/stage3.s.o
	nasm -felf32   ./jmpkrnl.s -o build/jmpkrnl.o
	nasm -felf32   ./drivers/kbd.s -o build/kbd.s.o

link:
	ld.lld -Tlinker.ld  -z noexecstack -o build/hfboot.elf build/*.o build/drivers/*.o build/include/*.o -v --verbose --trace --cref --Map=map.map
flpblt:
	dd if=/dev/zero of=floppy.img bs=512 count=2880
	dd if=build/stage1.bin of=floppy.img seek=0 bs=512 conv=notrunc
	dd if=build/stage2.bin of=floppy.img seek=1 bs=512 conv=notrunc
	dd if=build/hfboot.elf of=floppy.img seek=3 bs=512 conv=notrunc
