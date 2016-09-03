#include"rdtsc.h"
#include"creation_ovhd.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>

void creation_overhead(void)
{
  uint64_t start, end, pid;
  int status;
  
  start = meas_start();
  pid=fork();

  if(pid == 0)
    {
      exit(0);
    }
  
  else
    {
      wait(&status);
      end = meas_stop();
      printf("Process creation overhead:%lu\n", end-start);
    }
}

  
