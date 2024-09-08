#include "types.h"
#include "defs.h"

// send one character to the uart
void console_putchar(u8 c)
{
    uart_putc_sync(c);
}
