#include"proc_ovhd.h"
#include"rdtsc.h"
#include<stdio.h>
#include<stdint.h>

uint64_t start,end;

static void test_procedure(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g);

void procedure_call_overhead(void)
{
  start = meas_start();
  test_procedure(1,2,3,4,5,6,7); //calling test procedure
}

static void test_procedure(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g)
{
  int sum;
  end = meas_stop();
  sum = a+b+c+d+e+f+g;
  printf("Procedure call done: %d, overhead:%lu\n",sum, end-start);
}

