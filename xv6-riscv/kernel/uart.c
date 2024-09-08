// Uart driver based on the 16550a (https://opensocdebug.readthedocs.io/en/latest/02_spec/07_modules/dem_uart/uartspec.html)
// This basis is used b/c the xv6-riscv emulator uses this protocol

#include "memlayout.h"
#include "types.h"

// Uart Control Registers (these registers are mapped at UART0_BASE)
#define RHR 0x0UL               // Receiver Holding Register
#define THR 0x0UL               // Transmitter Holding Register
#define IER 0x1UL               // Interrupt Enable Register
#define ISR 0x2UL               // Interrupt Status Register
#define FCR 0x2UL               // FIFO Control Register
#define LCR 0x3UL               // Line Control Register
#define LSR 0x5UL               // Line Status Register
#define LSR_TX_IDLE (1 << 5)    // THR Empty bit

// Macro to obtain control register from uart base
#define Reg(reg) ((volatile unsigned char *)(UART0_BASE + (reg)))

#define ReadReg(reg) (*(Reg(reg)))
#define WriteReg(reg, v) (*(Reg(reg)) = (v))

// Synchronous call meaning we directly wait for the transmitt buffer 
// to be ready for transmitting and perform no locking 
void uart_putc_sync(u8 c)
{
    // TODO: disable interrupts on this line before transmitting
    while ((ReadReg(LSR) & LSR_TX_IDLE) ==  0)
        ;
    WriteReg(THR, c);

    // TODO: enable interrups after transmitt completes
}

