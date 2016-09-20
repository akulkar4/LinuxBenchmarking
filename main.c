#include<stdio.h>
#include"meas_ovhd.h"
#include"proc_ovhd.h"
#include"syscall_ovhd.h"
#include"creation_ovhd.h"
#include"cswitch_ovhd.h"
#include"cswitch_ovhd_thread.h"
#include"pagefault_ovhd.h"
#include"mem_bandwidth.h"

int main()
{
  process_overhead();
  thread_overhead();
  measurement_overhead();
  procedure_call_overhead();
  loop_overhead();
  system_call_overhead();
  
  context_switch_overhead();
  
  thread_context_switch_overhead();
  pagefault_overhead();
  memory_bandwidth();
  return 0;
}
