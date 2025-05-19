# TastyCrepeOS
A small kernel made in Assembly (a bit of a lot), C (kernel) and C++ (bootloader), and Bitbake? (according to tokei, it saw .inc files aka nasm includes and called it bitbake)

# Installation
First, read BUILD.md. Second, grab your favorite floppy disk and `dd` the built files manually. I will make an installation program but not now.

# Usage
Insert that floppy disk intonr your favorite 32-bit PC (make sure the kernel is on an ATA hard drive) then boot.



# Minimum Requirements
CPU: i686/Pentium Pro+
GPU: Maybe
RAM: 16M
Sanity: 68

# Contributors
Me, LLVM, I, and myself.

# WARNING
Do not go into the dev branch as it is outdated.
And if you really need to boot off of a hard drive patch stage2 and stage1 to use DL: 0x80 instead of 0x00