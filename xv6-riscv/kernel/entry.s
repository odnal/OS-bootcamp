.option .novrc # disable compressed instruction (i.e I want a consistent 32 bit alignment)

# initialize the bootloader

.section .text
.globl _entry
_entry:
    # wait for interrupts (essentially a nop)
    wfi

loopforever:
    j loopforever
    



