#include <stdint.h>

extern uint64_t _write_uart(void *val);

static inline uint64_t r_mhartid()
{
  uint64_t ra;
  asm volatile("csrr %0, mhartid" : "=r" (ra) );
  return ra;
}

void start(void)
{
    uint64_t ra = 0;
    ra = r_mhartid();

    if (!ra) {
        _write_uart("Hello, World\n");
    }

    while (1);
}
