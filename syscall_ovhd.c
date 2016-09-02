#include"syscall.h"
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>

void system_call_overhead(void)
{
  uint64_t start, end;

  start = meas_start();
  getpid();
  end = meas_stop();
  printf("System call(getpid) overhead is: %lu\n",end-start);
}
