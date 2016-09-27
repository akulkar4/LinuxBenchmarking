
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<sys/syscall.h>
#include <sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void system_call_overhead(void)
{
  uint64_t start, end;
  uint32_t i,j;
  int fd;
  float count_ns[1000],result[1000];

  fd=open("GRTAGS",O_RDONLY);
  struct stat stats;
 
  for(i = 0; i<1;i++)
  {
      start = meas_start();
      for(j=0;j<1;j++)
      {
          getppid();    
      }
      end = meas_stop();
      result[i] = ((end-start)/1);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("getppid overhead");
  float sd1 = standard_deviation(count_ns,1);
  printf("Standard deviation %.3f\n",sd1);
  
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          fstat(fd,&stats);     
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("fstat() overhead");
  float sd2 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd2);

}
