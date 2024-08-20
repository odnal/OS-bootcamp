OUTPUT_ARCH("riscv")

ENTRY(_entry)

MEMORY 
{
    ram : ORIGIN = 0x80000000, LENGTH = 128M
}

SECTIONS
{
    .text : { *(.text) } > ram
    .data : { *(.data) } > ram
    .bss :  { *(.bss)  } > ram
}
