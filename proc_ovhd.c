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
  uint32_t g1,g2,g3,g4,g5,g6,g7;
  float result,count_ns;
  int r ;
  uint32_t i;
  start = meas_start();
  for(i = 0; i<1000000;i++)
  {
    procedure_arg_0();  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0);
  count_ns = meas_convert_to_ns(result);
  printf("Proc 0 arguments overhead:%.3f ns\n",count_ns);
  
  uint32_t a;
  start = meas_start();
  for(i = 0; i< 1000000;i++)
  {
    procedure_arg_1(a);  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0); 
  count_ns = meas_convert_to_ns(result);
  printf("Proc 1 arguments overhead:%.3f\n",count_ns);

  uint32_t b1,b2;
  start = meas_start();
  for(i = 0; i< 1000000;i++)
  {
    procedure_arg_2(b1,b2);  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0);
  count_ns = meas_convert_to_ns(result);
  printf("Proc 2 arguments overhead:%.3f\n",count_ns);
  
  uint32_t c1,c2,c3;
  start = meas_start();
  for(i = 0; i< 1000000;i++)
  {
    procedure_arg_3(c1,c2,c3);  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0);
  count_ns = meas_convert_to_ns(result);
  printf("Proc 3 arguments overhead:%.3f\n",count_ns);
  
  uint32_t d1,d2,d3,d4;
  start = meas_start();
  for(i = 0; i< 1000000;i++)
  {
    procedure_arg_4(d1,d2,d3,d4);  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0);
  count_ns = meas_convert_to_ns(result);
  printf("Proc 4 arguments overhead:%.3f\n",count_ns);
  
  uint32_t e1,e2,e3,e4,e5;
  start = meas_start();
  for(i = 0; i< 1000000;i++)
  {
    procedure_arg_5(e1,e2,e3,e4,e5);  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0);
  count_ns = meas_convert_to_ns(result);
  printf("Proc 5 arguments overhead:%.3f\n",count_ns);
  
  uint32_t f1,f2,f3,f4,f5,f6;
  start = meas_start();
  for(i = 0; i< 1000000;i++)
  {
    procedure_arg_6(f1,f2,f3,f4,f5,f6);  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0);
  count_ns = meas_convert_to_ns(result);
  printf("Proc 6 arguments overhead:%.3f\n",count_ns);
  
  start = meas_start();
  for(i = 0; i< 1000000;i++)
  {
    procedure_arg_7(g1,g2,g3,g4,g5,g6,g7);  
  }
  end = meas_stop();
  result = ((end-start)/1000000.0);
  count_ns = meas_convert_to_ns(result);
  printf("Proc 7 arguments overhead:%.3f\n",count_ns);
}

void __attribute__  ((noinline)) procedure_arg_0(void)
{
    return;
}

void __attribute__  ((noinline)) procedure_arg_1(uint32_t a)
{
    return;
}

void __attribute__  ((noinline)) procedure_arg_2(uint32_t a, uint32_t b)
{
    return;
}

void __attribute__  ((noinline)) procedure_arg_3(uint32_t a, uint32_t b, uint32_t c)
{
    return;
}

void __attribute__  ((noinline)) procedure_arg_4(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    return;
}

void __attribute__  ((noinline)) procedure_arg_5(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    return;
}

void __attribute__  ((noinline)) procedure_arg_6(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    return;
}

void __attribute__  ((noinline)) procedure_arg_7(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
    return;
}
