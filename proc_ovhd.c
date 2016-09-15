#include"proc_ovhd.h"
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>

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
  volatile uint32_t g1,g2,g3,g4,g5,g6,g7;
  start = meas_start();
  procedure_arg_7(g1,g2,g3,g4,g5,g6,g7);
  start = meas_start();
  procedure_arg_0();
  //sleep(1);
  volatile uint32_t a;
  start = meas_start();
  procedure_arg_1(a);
  //sleep(1);
  volatile uint32_t b1,b2;
  start = meas_start();
  procedure_arg_2(b1,b2);
  //sleep(1);
  volatile uint32_t c1,c2,c3;
  start = meas_start();
  procedure_arg_3(c1,c2,c3);
  //sleep(1);
  volatile uint32_t d1,d2,d3,d4;
  start = meas_start();
  procedure_arg_4(d1,d2,d3,d4);
  //sleep(1);
  volatile uint32_t e1,e2,e3,e4,e5;
  start = meas_start();
  procedure_arg_5(e1,e2,e3,e4,e5);
  //sleep(1);
  volatile uint32_t f1,f2,f3,f4,f5,f6;
  start = meas_start();
  procedure_arg_6(f1,f2,f3,f4,f5,f6);
  //sleep(1);
 
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
