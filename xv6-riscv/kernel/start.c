#include "defs.h"
#include "riscv.h"

extern uint64_t _write_uart(void *val);

void start(void)
{
    uint64_t ra = 0;
    ra = r_mhartid();

    if (!ra) {
        _write_uart("Hello, World\n");
    }

    while (1);
}
