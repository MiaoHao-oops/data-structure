#ifndef _LINQUEUE_H_
#define _LINQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define OK 1
    //If a funtion functions well, it would return OK.
#define ERROR 0
    //If a funtion has something wrong, it would return ERROR.
#define OVERFLOW -1

typedef int Status;
typedef int ElemType;
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
}LQueue;

Status InitQueue(LQueue *pQ);
    //InitQueue add a head node to the queue Q.
Status EnQueue(LQueue Q, ElemType e);
    //EnQueue add the element e to the queue Q.

#endif