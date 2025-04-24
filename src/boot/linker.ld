ENTRY(_start)

SECTIONS {
	. = 0x9a00;

	.text ALIGN(4K) : {*(.text)}
	.data ALIGN(4K) : {*(.data)}
	.rodata ALIGN(4K) : {*(.rodata)}
	.bss ALIGN(4K) : {*(.bss COMMON)}
}
