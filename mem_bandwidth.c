/* Code to measure the memory bandwidth using memcpy()
 *
 */
#include "mem_bandwidth.h"
#include "rdtsc.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define TESTSIZE 1000000 //to transfer 8mb/8b = 1000000

__int128 *arraySrc, *arrayDst;

void memory_bandwidth(void)
{
  //declarations
  uint64_t i, start, end;
  uint8_t longSize;
  float count_ns, memBw;
  longSize = sizeof(__int128);
  
  //allocate arrays and fill something in the arrays
  arraySrc = calloc(TESTSIZE, longSize);
  arrayDst = calloc(TESTSIZE, longSize);
  for(i = 0; i < TESTSIZE; i++)
    {
      arraySrc[i] = 0xaaaaaaaaaaaaaaaa;
      arrayDst[i] = 0xbbbbbbbbbbbbbbbb;
    }
  
  //memcpy
  start = meas_start();
  memcpy(arrayDst, arraySrc, (TESTSIZE*longSize));
  end = meas_stop(); 
  count_ns = meas_convert_to_ns(end - start);
  printf("time taken by memcpy to  move the memory:%.3f ns\n",count_ns);
  
  //for loop
  start = meas_start();
  memcpy(arrayDst, arraySrc, (TESTSIZE*longSize));
  for(i=0; i< TESTSIZE; i++)
    {
      arrayDst[i] = arraySrc[i];
    }
  end = meas_stop(); 
  count_ns = meas_convert_to_ns(end - start);
  printf("time taken by a for loop to move the memory:%.3f ns\n",count_ns);

  // printf("Memory bandwidth:%Lf MB/s\n",(long double)((TESTSIZE*longSize*1000)/(count_ns)) );
 
}

