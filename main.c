#include<stdio.h>
#include"meas_ovhd.h"
#include"proc_ovhd.h"
#include"syscall_ovhd.h"
#include"creation_ovhd.h"
#include"cswitch_ovhd.h"
#include"cswitch_ovhd_thread.h"

int main()
{
    loop_overhead();
    process_overhead();
    thread_overhead();
    measurement_overhead();
    procedure_call_overhead();
    system_call_overhead();
    context_switch_overhead();
    thread_context_switch_overhead();
    return 0;
}
