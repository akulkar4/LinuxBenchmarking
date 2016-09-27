#include "mem_latency.h"
#include "rdtsc.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// #define LISTSIZE 64000
// #define STRIDECOUNT 1

struct node
{
    uint64_t data[32];
    struct node *next;
};

void memory_latency(uint64_t listSize, uint64_t listStride)
{
    uint64_t i, j, start, end;
    uint8_t longSize;
    float count_ns, result;
    struct node *head;
    struct node *curr;
    struct node *newnode;
    struct node **testPtr;

    //create a linked list that has LISTSIZE elements in it
    
    for(i=0; i<listSize; i++)
    {
        if(i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            for(j=0; j<32; j++)
            {
                head->data[j] = 0xaaaaaaaaaaaaaaaa;    
            }
            head->next = NULL;
            curr = head;
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            curr->next = newnode;
            for(j=0; j<32; j++)
            {
                newnode->data[j] = 0xaaaaaaaaaaaaaaaa;    
            }
            newnode->next = NULL;
            curr = newnode;
            curr->next = NULL;
        }
    }
    
    //iterate over list for number of strides
    testPtr = &head;
    start = meas_start();
    for(i=0; i<(listStride*listSize); i++)
    {
       if((*testPtr)->next == NULL)
       {
           testPtr = &head;
       }
       else
       {
           testPtr = &((*testPtr)->next);
       }
    }
    end = meas_stop();
    result = (end-start);
    count_ns = meas_convert_to_ns(result)/(float)(listSize*listStride);
    printf("%.3f\n",count_ns);
}

// void memory_latency(uint64_t listSize, uint64_t listStride)
// {
//     uint64_t testArray[listSize], start, end;
//     uint64_t *testPtr[listSize/listStride];
//     uint64_t **p = &testPtr[0];
//     uint32_t i,j;
//     float count_ns, result;
// 
//     
//     for(int i=0; i<listSize/listStride; i++)
//     {
//         if(i==(listSize/listStride) - 1)
//             testArray[i] = &testPtr[0];
//         else
//             testArray[i] = &testPtr[i+1];
//         
//         testPtr[i] = &testArray[i]; 
//     }
//     
//     start = meas_start();
//     for(int i=0; i<listStride; i++)
//     {
//         for(j=0; j<listSize; j++)
//         { 
//             p = **p;
//         }
//     }    
//     end = meas_stop();
//     result = (end - start);
//     count_ns = meas_convert_to_ns(result)/(float)(listSize*listStride);
//     printf("%.3f\n",count_ns);
// }