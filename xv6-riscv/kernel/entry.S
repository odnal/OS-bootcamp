# initialize the bootloader

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.globl _entry
_entry:

    la sp, stack_top
    li a0, 1024*4
    csrr a1, mhartid
    addi a1, a1, 1
    mul a0, a0, a1
    add sp, sp, a0

    call start

loopforever:
    j loopforever
    
.globl _write_uart
_write_uart:
    li t1, 0x10000000
    lb t2, (a0)
    beqz t2, _return
    sb t2, (t1)
    addi a0, a0, 1
    j _write_uart

_return:
    ret
