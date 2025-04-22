CC        := clang++
CFLAGS    := -nostdlib -Isrc/include -Wall -Wextra  \
             -fno-pie -fno-pic -ffreestanding -fno-stack-protector \
             -fno-strict-aliasing --target=i686-elf -g \
             -fno-omit-frame-pointer  -fno-builtin \
             -mno-red-zone -fno-exceptions  -fno-rtti -D_LIBCPP_HAS_NO_THREADS

BUILD_DIR := build
SRCS      := $(wildcard *.cxx) $(wildcard drivers/*.cxx) $(wildcard include/*.cxx)
OBJS      := $(SRCS:%.cxx=$(BUILD_DIR)/%.o)

.PHONY: all clean
all: $(OBJS)

$(BUILD_DIR)/%.o: %.cxx
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
