#include"rdtsc.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include <sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void pagefault_overhead()
{
  uint64_t start,end;
  float count_ns,result;
  char * dataPtr;
  int pagesize,fd;
  fd=open("notes.txt",O_RDWR);
  pagesize = getpagesize();
  
  start = meas_start();
  for(int i=0; i<1000;i++)
  {
      dataPtr = mmap (0,pagesize,(PROT_READ | PROT_WRITE),MAP_SHARED,fd,0);
      dataPtr[0] = '1';
      munmap(dataPtr, pagesize);      
  }
  end = meas_stop();
  result = (end-start)/1000.0;
  count_ns = meas_convert_to_ns(result);
  printf("The pagefault overhead is %.3f ns\n",count_ns);
}