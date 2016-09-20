
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<sys/syscall.h>

void system_call_overhead(void)
{
  uint64_t start, end;
  float count_ns,result;

  start = meas_start();
  for(int i=0;i<1000000;i++)
  {
      getppid();      
  }
  end = meas_stop();
  result = ((end-start)/1000000.0); 
  count_ns = meas_convert_to_ns(result);
  printf("getppid overhead:%.3f ns\n",count_ns);

}
