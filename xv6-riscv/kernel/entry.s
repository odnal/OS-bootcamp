.option .novrc # disable compressed instruction (i.e I want a consistent 32 bit alignment)

# initialize the bootloader

.section .text
.globl _entry
_entry:
    csrr a0, mhartid
    bnez a0, loopforever
    j _write_uart

loopforever:
    j loopforever
    
_write_uart:
    li a0, 0x10000000 # virt uart0 base address
    li a1, 0x55       # ascii 'U'
    sb a1, (a0)



