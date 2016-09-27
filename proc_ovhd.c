#include"proc_ovhd.h"
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include <math.h>

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
  
  float result[1000],count_ns[1000];
  int r ;
  uint32_t i,j;
  
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_0();      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 0 arguments overhead");
  float sd1 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd1);
  
  uint32_t a;
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_1(a);      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 1 arguments overhead");
  float sd2 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd2);

  uint32_t b1,b2;
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_2(b1,b2);      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 2 arguments overhead");
  float sd3 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd3);
  
  uint32_t c1,c2,c3;
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_3(c1,c2,c3);      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 3 arguments overhead");
  float sd4 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd4);
  
  uint32_t d1,d2,d3,d4;
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_4(d1,d2,d3,d4);      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 4 arguments overhead");
  float sd5 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd5);
  
  uint32_t e1,e2,e3,e4,e5;
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_5(e1,e2,e3,e4,e5);      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 5 arguments overhead");
  float sd6 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd6);
  
  uint32_t f1,f2,f3,f4,f5,f6;
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_6(f1,f2,f3,f4,f5,f6);      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 6 arguments overhead");
  float sd7 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd7);
  
  uint32_t g1,g2,g3,g4,g5,g6,g7;
  for(i = 0; i<1000;i++)
  {
      start = meas_start();
      for(j=0;j<1000;j++)
      {
          procedure_arg_7(g1,g2,g3,g4,g5,g6,g7);      
      }
      end = meas_stop();
      result[i] = ((end-start)/1000);
      count_ns[i] = meas_convert_to_ns(result[i]);        
  }
  printf("Proc 7 arguments overhead");
  float sd8 = standard_deviation(count_ns,1000);
  printf("Standard deviation %.3f\n",sd8 );
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
