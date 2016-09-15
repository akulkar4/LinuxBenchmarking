
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<sys/syscall.h>

void system_call_overhead(void)
{
  uint64_t start, end;
  float count_ns;

  start = meas_start();
  getppid();
  end = meas_stop();
  count_ns = meas_convert_to_us(end - start);
  printf("getppid overhead:%.3f ns\n",count_ns);

}
