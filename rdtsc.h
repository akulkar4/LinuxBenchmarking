#ifndef RDTSC_H
#define RDTSC_H

#include<stdint.h>
#include<math.h>
#include<stdio.h>

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

static __inline__ float meas_convert_to_ns(float ticks)
{
  /*We will be converting the RDTSC cycles to nanoseconds or us*/
  float ns_count;
  ns_count = ticks * 0.4;
  return ns_count;
}

static __inline__ float standard_deviation(float data[], int n)
{
    float mean=0.0, sum_deviation=0.0;
    int i;
    for(i=0; i<n;++i)
    {
        mean+=data[i];
    }
    mean=mean/n;
    printf(": %.3f\n",mean);
    for(i=0; i<n;++i)
    sum_deviation+=(data[i]-mean)*(data[i]-mean);
    return sqrt(sum_deviation/n);           
}
#endif
