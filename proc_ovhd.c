#include"proc_ovhd.h"
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>

volatile uint64_t start,end;

void __attribute__ ((noinline)) procedure_arg_0(void);
void __attribute__ ((noinline)) procedure_arg_1(uint32_t a);
void __attribute__ ((noinline)) procedure_arg_2(uint32_t a,uint32_t b);
void __attribute__ ((noinline)) procedure_arg_3(uint32_t a,uint32_t b,uint32_t c);
void __attribute__ ((noinline)) procedure_arg_4(uint32_t a,uint32_t b,uint32_t c,uint32_t d);
void __attribute__ ((noinline)) procedure_arg_5(uint32_t a,uint32_t b,uint32_t c,uint32_t d, uint32_t e);
void __attribute__ ((noinline)) procedure_arg_6(uint32_t a,uint32_t b,uint32_t c,uint32_t d, uint32_t e,uint32_t f);
void __attribute__ ((noinline)) procedure_arg_7(uint32_t a,uint32_t b,uint32_t c,uint32_t d, uint32_t e,uint32_t f, uint32_t g);


void procedure_call_overhead(void)
{
  volatile int a,b,c,d,e,f,g;
  
  start = meas_start();
  procedure_arg_7(a,b,c,d,e,f,g);
  start = meas_start();
  procedure_arg_6(a,b,c,d,e,f);
  start = meas_start();
  procedure_arg_5(a,b,c,d,e);
  start = meas_start();
  procedure_arg_4(a,b,c,d);
  start = meas_start();
  procedure_arg_3(a,b,c);
  start = meas_start();
  procedure_arg_2(a,b);
  start = meas_start();
  procedure_arg_1(a);
  start = meas_start();
  procedure_arg_0();
}

void __attribute__  ((noinline)) procedure_arg_0(void)
{
  end = meas_stop();
  printf("Proc zero arguments overhead:%lu\n",end-start);
}

void __attribute__  ((noinline)) procedure_arg_1(uint32_t a)
{
  end = meas_stop();
  printf("Proc one arguments overhead:%lu\n",end-start);
}

void __attribute__  ((noinline)) procedure_arg_2(uint32_t a, uint32_t b)
{
  end = meas_stop();
  printf("Proc two arguments overhead:%lu\n",end-start);
}

void __attribute__  ((noinline)) procedure_arg_3(uint32_t a, uint32_t b, uint32_t c)
{
  end = meas_stop();
  printf("Proc three arguments overhead:%lu\n",end-start);
}

void __attribute__  ((noinline)) procedure_arg_4(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
  end = meas_stop();
  printf("Proc four arguments overhead:%lu\n",end-start);
}

void __attribute__  ((noinline)) procedure_arg_5(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
  end = meas_stop();
  printf("Proc five arguments overhead:%lu\n",end-start);
}

void __attribute__  ((noinline)) procedure_arg_6(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
  end = meas_stop();
  printf("Proc six arguments overhead:%lu\n",end-start);
}

void __attribute__  ((noinline)) procedure_arg_7(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
  end = meas_stop();
  printf("Proc seven arguments overhead:%lu\n",end-start);
}
