/* Code to measure the context switch overhead when two threads keep pinging between
 * each other implemented using semaphores.
 */
#include "cswitch_ovhd_thread.h"
#include "rdtsc.h"
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semPing, semPong;
uint64_t start, end, testStart, testEnd, semOvhd;
float ovhdCnt;

void threadOneFn(void *arg);
void threadTwoFn(void *arg);

void thread_context_switch_overhead(void)
{
    sem_init(&semPing, 0, 0);
    sem_init(&semPong, 0, 1);

    //test overhead
    testStart = meas_start();
    for(int i=0; i<1000; i++)
    {
        sem_post(&semPing);
        sem_wait(&semPing);
    }
    testEnd = meas_stop();
    semOvhd = (testEnd - testStart)/1000.0;
    ovhdCnt = meas_convert_to_ns(semOvhd);
    printf("Semaphore overhead is %.3f ns\n",ovhdCnt);

    pthread_t threadOne, threadTwo;
    pthread_create(&threadOne, NULL, (void *) &threadOneFn, NULL);
    pthread_create(&threadTwo, NULL, (void *) &threadTwoFn, NULL);
    pthread_join(threadOne, NULL);
    pthread_join(threadTwo, NULL);
}

void threadOneFn(void *arg)
{
    float count_ns[100],result[100];
    for(int i=0;i<100;i++)
    {
        start = meas_start();
        for(int j = 0; j<100; j++)
        {
            sem_post(&semPing);
            sem_wait(&semPong);
        }    
        end = meas_stop();
        result[i] = (end-start)/200.0; 
        count_ns[i] = meas_convert_to_ns(result[i]);
    }
    printf("Thread context switch overhead");
    float sd1 = standard_deviation(count_ns,100);
    printf("Standard deviation %.3f\n",sd1);
    return;
}

void threadTwoFn(void *arg)
{
    for(int i=0;i<100;i++)
    {
        for(int j=0; j<100; j++)
        {
            sem_wait(&semPing);
            sem_post(&semPong);
        }
    }
    return;
}
