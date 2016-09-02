#include"meas_ovhd.h"
#include"rdtsc.h"

#include<stdio.h>
#include<stdint.h>
#include<unistd.h>

void measurement_overhead()
{
  uint64_t start,end;

  uint64_t sum = 0;
  for(int i=0; i<COUNT;i++)
    {
      start = meas_start();
      /* code to be measure, right now nothing */ 
      end = meas_stop();
      
      sum = sum + (end-start);
    }
 
 printf("%lu\n",sum/COUNT);
}
