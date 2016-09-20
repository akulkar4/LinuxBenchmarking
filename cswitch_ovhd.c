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
  int pingfd[2];
  int pongfd[2];
  pid_t pid;
  size_t ret;
  int pipe_result;
  float count_ns,result,pipeOvhd;
  uint64_t testStart, testEnd;

  //create two pipes
  pipe_result = pipe(pingfd);
  if (pipe_result < 0)
    {
      perror("ping");
      exit (1);
    }
  pipe_result = pipe(pongfd);
  if (pipe_result < 0)
  {
    perror("pong");
    exit (1);
  }

  //measuring testPipe read-write latency before forking
  /*testStart = meas_start();
  for(int i=0;i<2000.0;i++)
  {
   ret = write(pongfd[1], &testStart, sizeof(testStart));
   ret = read(pongfd[0], &testStart, sizeof(testStart));      
  }
  testEnd = meas_stop();
  pipeOvhd = (testStart - testEnd)/2000.0;
  count_ns = meas_convert_to_ns(pipeOvhd);
  //pipeOvhd =  testEnd - testStart;
  printf("Pipe call overhead: %.3f\n",pipeOvhd);*/
  
  pid = fork();
  if (pid == 0)
    {
      //sample time before the context switch
      start = meas_start();
      for(int i=0; i<1000;i++)
      {
        ret = write(pingfd[1], &start, sizeof(start));
        ret = read(pongfd[0], &testStart, sizeof(testStart));      
      }
      end = meas_stop();
      result = (end-start)/2000.0;
      count_ns = meas_convert_to_ns(result);
      printf("Context switch overhead: %.3f ns\n",count_ns);
      exit (0);
    }
  else
    {
      uint64_t start;
      for(int i=0;i<1000;i++)
      {
          ret = read (pingfd[0], &start, sizeof(start));
          ret = write(pongfd[1], &start, sizeof(start));      
      }
    }
}
