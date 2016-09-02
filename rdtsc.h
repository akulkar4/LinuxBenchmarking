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

#endif
