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
  float count_ns;
  char * dataPtr;
  char buffer;
  
  int pagesize,fd;
  fd=open("notes.txt",O_RDWR);
  pagesize = getpagesize();
  //first lets mmap a disk file
  
  dataPtr = mmap (0,pagesize,(PROT_READ | PROT_WRITE),MAP_SHARED,fd,0);
  if(dataPtr == MAP_FAILED)
  {
      printf("Oops!\n");
  }
  start = meas_start();
  dataPtr[0] = '1';
  end = meas_stop();
  
  count_ns = meas_convert_to_us(end - start);
  printf("The pagefault overhead is %.3f ns\n",count_ns);
}