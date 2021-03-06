#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"meas_ovhd.h"
#include"proc_ovhd.h"
#include"syscall_ovhd.h"
#include"creation_ovhd.h"
#include"cswitch_ovhd.h"
#include"cswitch_ovhd_thread.h"
#include"pagefault_ovhd.h"
#include"mem_bandwidth.h"
#include"mem_latency.h"

int main(int argc, char *argv[])
{
    uint64_t listSize = atoi(argv[1]);
    uint64_t listStride = atoi(argv[2]);
    process_overhead();
    thread_overhead();
    loop_overhead();
    measurement_overhead();
    procedure_call_overhead();
    system_call_overhead();
    context_switch_overhead();
    thread_context_switch_overhead();
    pagefault_overhead();
    memory_bandwidth();
    memory_latency(listSize,listStride);
    return 0;
}
