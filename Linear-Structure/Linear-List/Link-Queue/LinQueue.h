#ifndef _LINQUEUE_H_
#define _LINQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

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

#endif