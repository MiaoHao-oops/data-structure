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

Status EnQueue(LQueue *pQ, ElemType e)
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
    pQ->rear->next = p;
    pQ->rear = p;
    return OK;
}

Status DeQueue(LQueue *pQ, ElemType *pe)
{
    if (pQ->rear == pQ->front)
    {
            //The queue is empty.
        return ERROR;
    }

    QNode *p;
    p = pQ->front->next;
    *pe = p->data;
    pQ->front->next = p->next;
    if (pQ->rear == p)
    {   
            //There is only one element in the queue.
        pQ->rear = pQ->front;
    }
    free(p);
    return OK;
}