#include "LinQueue.h"

Status InitQueue(LQueue *pQ)
{
    pQ->rear = pQ->front = (QNode *)malloc(sizeof(QNode));
    if (!pQ->front)
    {
            //The allocation is unsucceeded.
        return ERROR;
    }
    pQ->front->next = NULL;
    return OK;
}

Status EnQueue(LQueue Q, ElemType e)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    if (!p)
    {   
            //The allocation is unsucceeded.
        return ERROR;
    }
        //Add p to the rear of the queue.
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LQueue Q, ElemType *pe)
{
    if (Q.rear == Q.front)
    {
            //The queue is empty.
        return ERROR;
    }

    QNode *p;
    p = Q.front->next;
    *pe = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {   
            //There is only one element in the queue.
        Q.rear = Q.front;
    }
    free(p);
    return OK;
}