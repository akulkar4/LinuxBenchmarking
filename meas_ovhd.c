#include"meas_ovhd.h"
#include"rdtsc.h"

#include<stdio.h>
#include<stdint.h>
#include<unistd.h>

void measurement_overhead()
{
  uint64_t start,end;
  float count_ns;
  uint64_t sum = 0;
  for(int i=0; i<COUNT;i++)
    {
      start = meas_start();
      /* code to be measure, right now nothing */ 
      end = meas_stop();
      sum = sum + (end-start);
    }
  
  count_ns = meas_convert_to_us(end - start);
  printf("The measurement overhead is %.3f ns\n",count_ns);
}

void loop_overhead()
{
    //Finding out the overhead of an empty loop so that it can be subtracted when needed
    uint64_t start,end;
    uint64_t dummy;
    float count_ns;
    uint32_t i=0;
    start = meas_start();
    for(i=0;i<1000;i++)
    {
     asm volatile("");
     dummy += i;
    }
    end = meas_stop();
    count_ns = meas_convert_to_us(end-start);
    count_ns = count_ns/1000;
    printf("The loop overhead is %.3f ns\n", count_ns);
    printf("Dummy: %lu\n",dummy);
}
