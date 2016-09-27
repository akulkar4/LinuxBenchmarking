#include"meas_ovhd.h"
#include"rdtsc.h"

#include<stdio.h>
#include<stdint.h>
#include<unistd.h>

void measurement_overhead()
{
  uint64_t start,end;
  float count_ns;
  uint64_t sum = 0;
  for(int i=0; i<COUNT;i++)
    {
      start = meas_start();
      /* code to be measure, right now nothing */ 
      end = meas_stop();
      sum = sum + (end-start);
    }
  
  count_ns = meas_convert_to_ns(end - start);
  printf("The measurement overhead is %.3f ns\n",count_ns);
}

void loop_overhead()
{
    //Finding out the overhead of an empty loop so that it can be subtracted when needed
    uint64_t start,end;
    float count_ns[1000],result[1000];
    uint32_t i,j;
    
    
    for(i=0;i<1000;i++)
    {
        start = meas_start();
        for(j=0;j<1000;j++)
        {
            
        }
        end = meas_stop();
        result[i] = (end-start)/1000.0;
        count_ns[i] = meas_convert_to_ns(result[i]);
    }
    
    printf("The loop overhead");
    float sd = standard_deviation(count_ns,1000);
    printf("The standard deviation is %.3f ns\n",sd);
}