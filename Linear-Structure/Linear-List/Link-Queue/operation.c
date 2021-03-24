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