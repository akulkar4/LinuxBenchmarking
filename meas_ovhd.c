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
