#include"meas_ovhd.h"

#include<stdio.h>
#include<stdint.h>
#include<unistd.h>

void measurement_overhead()
{
  uint64_t start,end;
  unsigned cycles_high,cycles_low,cycles_high1,cycles_low1;

  uint64_t sum = 0;
  for(int i=0; i<COUNT;i++)
    {
      asm volatile("CPUID\n\t"
		   "RDTSC\n\t"
		   "mov %%edx, %0\n\t"
		   "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
		   "%rax", "%rbx", "%rcx", "%rdx");
      
      /* code to be measure, right now nothing */ 
      asm volatile("RDTSCP\n\t"
		   "mov %%edx, %0\n\t"
		   "mov %%eax, %1\n\t"
		   "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1):: "%rax",
		   "%rbx", "%rcx", "%rdx");

      start = ((uint64_t)cycles_high) << 32 | (uint64_t)cycles_low;
      end = ((uint64_t)cycles_high1) << 32 | (uint64_t)cycles_low1;
      sum = sum + (end-start);
    }
 
 printf("%lu\n",sum/COUNT);
}
