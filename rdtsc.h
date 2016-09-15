#ifndef RDTSC_H
#define RDTSC_H

#include<stdint.h>

static __inline__ uint64_t meas_start()
{
  unsigned cycles_high, cycles_low;
  
  asm volatile("CPUID\n\t"
	       "RDTSC\n\t"
	       "mov %%edx, %0\n\t"
	       "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
	       "%rax", "%rbx", "%rcx", "%rdx");
                  
  return (((uint64_t)cycles_high) << 32 | (uint64_t)cycles_low);
}

static __inline__ uint64_t meas_stop()
{
  unsigned cycles_high, cycles_low;
  asm volatile("RDTSCP\n\t"
	       "mov %%edx, %0\n\t"
	       "mov %%eax, %1\n\t"
	       "CPUID\n\t": "=r" (cycles_high), "=r" (cycles_low):: "%rax",
	       "%rbx", "%rcx", "%rdx");

  return (((uint64_t)cycles_high) << 32 | (uint64_t)cycles_low);
}

static __inline__ float meas_convert_to_us(float ticks)
{
  /*We will be converting the RDTSC cycles to nanoseconds or us*/
  float ns_count;
  ns_count = ticks * 0.4;
  return ns_count;
}
#endif
