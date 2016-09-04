#include "cswitch_ovhd.h"
#include "rdtsc.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void context_switch_overhead(void)
{
        int pipefd[2];
        pid_t pid;
        int result;

        result = pipe(pipefd);
        if (result < 0)
        {
                //failure in creating a pipe
                perror("pipe");
                exit (1);
        }

        pid = fork();
        if (pid < 0)
        {
                perror ("fork");
                exit(2);
        }

        if (pid == 0)
        {
                uint64_t start;

                //sample time before the context switch
                start = meas_start();

                //Writing start time to the pipe
                write(pipefd[1], &start, sizeof(start));

                exit (0);
        }
        else
        {
                uint64_t start, end;

                //Reading start time from the pipe
                read (pipefd[0], &start, sizeof(start));

                //sampling rdtscp after context switch
                end = meas_stop();
                printf("Context switch overhead: %lu\n",end-start);
        }
}
