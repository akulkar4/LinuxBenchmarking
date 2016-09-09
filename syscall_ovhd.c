#include"syscall.h"
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<sys/syscall.h>

void system_call_overhead(void)
{
  uint64_t start, end;
  float count_ns;
  int cpu;
  
  start = meas_start();
  //getpid();
  syscall(SYS_getcpu, &cpu, NULL, NULL);
  end = meas_stop();
  count_ns = meas_convert_to_us(end - start);
  printf("System call(getpid) overhead is: %.3f ns\n",count_ns);
}
