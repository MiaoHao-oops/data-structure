#ifndef _CIQUEUE_H_
#define _CIQUEUE_H_

#include<stdio.h>
#include<stdlib.h>

#define OK 1
    //If a funtion functions well, it would return OK.
#define ERROR 0
    //If a funtion has something wrong, it would return ERROR.
#define OVERFLOW -1

#define INIT_SIZE 100

typedef int Status;
typedef int ElemType;
typedef struct 
{
    ElemType *base;
    int front;
        //Front points to the front node of the queue
    int raer;
        //Rear points to the next node of the end of the queue;
}CiQueue;

Status InitQueue(CiQueue *pQ);


#endif