/* Code to measure the context switch overhead when two threads keep pinging between
 * each other implemented using semaphores.
 */
#include "cswitch_ovhd_thread.h"
#include "rdtsc.h"
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semOne, semTwo;
uint64_t start, end, testStart, testEnd, semOvhd;
float count_ns;

void threadOneFn(void *arg);
void threadTwoFn(void *arg);

void thread_context_switch_overhead(void)
{
        sem_init(&semOne, 0, 0);
        sem_init(&semTwo, 0, 1);

        //test overhead
        testStart = meas_start();
        sem_post(&semOne);
        sem_wait(&semOne);
        testEnd = meas_stop();
        semOvhd = testEnd - testStart;

        pthread_t threadOne, threadTwo;
        pthread_create(&threadOne, NULL, (void *) &threadOneFn, NULL);
        pthread_create(&threadTwo, NULL, (void *) &threadTwoFn, NULL);
        pthread_join(threadOne, NULL);
        pthread_join(threadTwo, NULL);
}

void threadOneFn(void *arg)
{
        //for (;;)
        //{
        //        sem_wait(&semTwo);
        //        start = meas_start();
        //        sem_post(&semOne);
        //}
        sem_wait(&semOne);
        end = meas_stop();
        count_ns = meas_convert_to_us(end-start-semOvhd);
        printf("Thread context switch overhead: %.3f ns\n",count_ns);
        return;
}

void threadTwoFn(void *arg)
{
        //for (;;)
        //{
        //        sem_wait(&semOne);
        //        end = meas_stop();
        //        sem_post(&semTwo);
        //}
        start = meas_start();
        sem_post(&semOne);
        return;
}
