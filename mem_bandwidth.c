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

#define _GNU_SOURCE
#define MEM_TOTAL_SIZE 8000000 //in bytes
#define MEM_BLOCK_SIZE 8000     // in bytes

uint8_t *arraySrc, *arrayDst;
//uint8_t arraySrc[2*MEM_TOTAL_SIZE];
//uint8_t arrayDst[2*MEM_TOTAL_SIZE];
void memory_bandwidth(void)
{
  //declarations
  uint64_t i, start, end;
  uint8_t elementSize;
  float count_ns, memBw, result,bw;
  elementSize = sizeof(uint8_t);
  char *memSrc = NULL;
  
  //allocate arrays and fill something in the arrays
 arraySrc = calloc(4*MEM_TOTAL_SIZE, elementSize);
 arrayDst = calloc(4*MEM_TOTAL_SIZE, elementSize);
 
  for(i = 0; i < MEM_TOTAL_SIZE; i++)
    {
      arraySrc[i] = 0xaa;
      arrayDst[i] = 0xbb;
    }
  memSrc = (char *)arraySrc;
  
  start = meas_start();
  memcpy(arrayDst, arraySrc, (MEM_TOTAL_SIZE/8));
  end = meas_stop(); 
  count_ns = meas_convert_to_ns(end - start);
  printf("Memcpy (1MB):%Lf MB/s\n",(long double)(125.0*(MEM_TOTAL_SIZE/count_ns)));
  
  start = meas_start();
  memcpy(arrayDst, arraySrc, (MEM_TOTAL_SIZE));
  end = meas_stop(); 
  count_ns = meas_convert_to_ns(end - start);
  printf("Memcpy (8MB):%Lf MB/s\n",(long double)(1000.0*(MEM_TOTAL_SIZE/count_ns)));
 
  start = meas_start();
  memcpy(arrayDst, arraySrc, (2*MEM_TOTAL_SIZE));
  end = meas_stop();
  count_ns = meas_convert_to_ns(end - start);
  printf("Memcpy (16MB):%Lf MB/s\n",(long double)(2000.0*(MEM_TOTAL_SIZE/count_ns)));
  
  start = meas_start();
  memset(arrayDst,0, (2*MEM_TOTAL_SIZE));
  end = meas_stop();
  count_ns = meas_convert_to_ns(end - start);
  printf("Memset (16MB):%Lf MB/s\n",(long double)(2000.0*(MEM_TOTAL_SIZE/count_ns)));
  
}

