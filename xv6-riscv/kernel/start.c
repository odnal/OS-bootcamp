#include "defs.h"
#include "riscv.h"

void main();

void start(void)
{
    uint64_t ra = 0;
    ra = r_mhartid();

    if (!ra) {
        main();
    }

    while (1);
}
