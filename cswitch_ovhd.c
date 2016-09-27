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
  float count_ns[100], result[100], pipeOvhd;
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
  testStart = meas_start();
  for(int i=0;i<2000.0;i++)
  {
   ret = write(pongfd[1], &testStart, sizeof(testStart));
   ret = read(pongfd[0], &testStart, sizeof(testStart));      
  }
  testEnd = meas_stop();
  pipeOvhd = (testEnd - testStart)/2000.0;
  pipeOvhd = meas_convert_to_ns(pipeOvhd);
  
  printf("Pipe call overhead: %.3f\n",pipeOvhd);
  
  pid = fork();
  if (pid == 0)
    {
      //sample time before the context switch
      for(int i=0; i<100;i++)
      {
          start = meas_start();
          for(int j=0; j<100; j++)
          {
              ret = write(pingfd[1], &start, sizeof(start));
              ret = read(pongfd[0], &testStart, sizeof(testStart));      
          }
          end = meas_stop();
          result[i] = (end-start)/200.0;
          count_ns[i] = meas_convert_to_ns(result[i]);
      }
      printf("Process context switch overhead");
      float sd1 = standard_deviation(count_ns,100);
      printf("Standard deviation %.3f\n",sd1);
      exit (0);
    }
  else
    {
      uint64_t start;
      for(int i=0;i<100;i++)
      {
          for(int j=0; j<100; j++)
          {
              ret = read (pingfd[0], &start, sizeof(start));
              ret = write(pongfd[1], &start, sizeof(start));      
          }
      }
    }
}
