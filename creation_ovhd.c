#include"rdtsc.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>

void process_overhead(void);
void thread_overhead(void);
void random_fn(void *ptr);

void process_overhead(void)
{
  uint64_t start, end, pid;
  int status;
  float count_ns,result;
  
  start = meas_start();
  for(int i=0;i<1000;i++)
  {
      pid=fork();
      if(pid == 0)
      {
          exit(0);
      }
      else
      {
          wait(&status);          
      }
  }
  end = meas_stop();
  result = (end-start)/1000.0;
  count_ns = meas_convert_to_ns(result);
  printf("Process creation overhead:%.3f ns\n", count_ns);
}

void thread_overhead(void)
{
  void *ptr;
  pthread_t thread_one;
  uint64_t start, end;
  float count_ns,result;
  
  start = meas_start();
  for(int i=0;i<1000;i++)
  {
    pthread_create(&thread_one,NULL,(void *)&random_fn,ptr); 
    pthread_join(thread_one,NULL);    
  }
  end = meas_stop();
  result = (end-start)/1000.0;
  count_ns = meas_convert_to_ns(result);
  printf("Thread creation overhead:%.3f ns\n", count_ns);
}

void random_fn(void *ptr)
{
    return;
}
