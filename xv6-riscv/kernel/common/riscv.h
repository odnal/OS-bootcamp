#include "defs.h"

static inline uint64_t r_mhartid();

static inline uint64_t r_mhartid()
{
  uint64_t ra;
  asm volatile("csrr %0, mhartid" : "=r" (ra) );
  return ra;
}
