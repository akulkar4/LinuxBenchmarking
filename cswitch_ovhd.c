#include "cswitch_ovhd.h"
#include "rdtsc.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint64_t start, end;
void context_switch_overhead(void)
{
  int pipefd[2];
  pid_t pid;
  size_t ret;
  int result;
  
  result = pipe(pipefd);
  if (result < 0)
    {
      //failure in creating a pipe
      perror("pipe");
      exit (1);
    }
  
  pid = fork();
  if (pid == 0)
    {
      //sample time before the context switch
      start = meas_start();
      //Writing start time to the pipe
      ret = write(pipefd[1], &start, sizeof(start));
      exit (0);
    }
  else
    {
      uint64_t start;
      float count_ns;
      //Reading start time from the pipe
      ret = read (pipefd[0], &start, sizeof(start));
      //sampling rdtscp after context switch
      end = meas_stop();
      count_ns = meas_convert_to_us(end-start);
      printf("Context switch overhead: %.3f ns\n",count_ns);
    }
}
