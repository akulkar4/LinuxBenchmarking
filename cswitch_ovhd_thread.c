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

void threadOneFn(void *arg);
void threadTwoFn(void *arg);

void thread_context_switch_overhead(void)
{
    sem_init(&semPing, 0, 0);
    sem_init(&semPong, 0, 1);

    //test overhead
    /*testStart = meas_start();
    sem_post(&semTwo);
    sem_wait(&semTwo);
    testEnd = meas_stop();
    semOvhd = testEnd - testStart;
    printf("Semaphore overhead is %lu\n",semOvhd);*/

    pthread_t threadOne, threadTwo;
    pthread_create(&threadOne, NULL, (void *) &threadOneFn, NULL);
    pthread_create(&threadTwo, NULL, (void *) &threadTwoFn, NULL);
    pthread_join(threadOne, NULL);
    pthread_join(threadTwo, NULL);
}

void threadOneFn(void *arg)
{
    float count_ns,result;
    start = meas_start();
    for(int i=0;i<1000;i++)
    {
        sem_post(&semPing);
        sem_wait(&semPong);    
    }
    end = meas_stop();
    result = (end-start)/2000.0;
    count_ns = meas_convert_to_ns(result);
    printf("Thread context switch overhead: %.3f ns\n",count_ns);
    return;
}

void threadTwoFn(void *arg)
{
    for(int i=0;i<1000;i++)
    {
        sem_wait(&semPing);
        sem_post(&semPong);
    }
    return;
}
