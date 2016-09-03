#include"rdtsc.h"
#include"creation_ovhd.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>

static void process_overhead(void);
static void thread_overhead(void);
static void *random_fn(void *ptr);

void creation_overhead(void)
{
  process_overhead();
  thread_overhead();
}


static void process_overhead(void)
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

static void thread_overhead(void)
{
  uint64_t start, end;
  void *ptr;

  pthread_t thread_one;
  start = meas_start();
  pthread_create(&thread_one,NULL,random_fn,ptr); 
  pthread_join(thread_one,NULL);
  end = meas_stop();
  printf("Thread creation overhead:%lu\n", end-start);
}

static void *random_fn(void *ptr)
{
  return NULL;
}
