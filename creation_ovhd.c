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
  float count_ns[1000],result[1000];
 
  for(int i=0;i<100;i++)
  {
      start = meas_start();
      for(int j=0;j<100;j++)
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
      result[i] = (end-start)/100.0;
      count_ns[i] = meas_convert_to_ns(result[i]);
  }
  
  printf("Process creation overhead:");
  float sd = standard_deviation(count_ns,100);
  printf("Standard deviation is %.3f\n",sd);
}

void thread_overhead(void)
{
  void *ptr;
  pthread_t thread_one;
  uint64_t start, end;
  float count_ns[1000],result[1000];
  
  
  for(int i=0;i<100;i++)
  {
      start = meas_start();
      for(int j=0;j<100;j++)
      {
        pthread_create(&thread_one,NULL,(void *)&random_fn,ptr); 
        pthread_join(thread_one,NULL);  
      }
      end = meas_stop();
      result[i] = (end-start)/100.0;
      count_ns[i] = meas_convert_to_ns(result[i]);
  } 
  printf("Thread creation overhead:");
  float sd = standard_deviation(count_ns,100);
  printf("Standard deviation is %.3f\n",sd);
}

void random_fn(void *ptr)
{
    return;
}
