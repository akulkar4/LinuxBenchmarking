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
  uint32_t ret;
  char * dataPtr;
  
  int pagesize,fd;
  fd=open("GRTAGS",O_RDONLY);
  struct stat stats;
  fstat(fd,&stats);
 
  posix_fadvise(fd,0,stats.st_size,POSIX_FADV_DONTNEED);
  dataPtr = mmap (NULL,stats.st_size,PROT_READ,MAP_SHARED,fd,0);    
  start = meas_start();
  ret = dataPtr[10];
  end = meas_stop();
  munmap(dataPtr,stats.st_size);       
  result = (end-start);
  count_ns = meas_convert_to_ns(result);
  
  printf("Pagefault Overhead is %.3f\n",count_ns);
  
}