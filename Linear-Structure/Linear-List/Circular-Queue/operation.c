#include "CiQueue.h"

Status InitQueue(CiQueue *pQ)
{
    pQ->base = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if (!pQ->base)
    {
            //The allocation is unsucceeded.
        return ERROR;
    }
    pQ->front = 0;
    pQ->raer = 0;
    return OK;
}

int IsEmpty(CiQueue Q)
{
    if (Q.front == Q.raer)
    {
            //The CiQueue Q is empty.
        return 1;
    }
        //The CiQueue Q is not empty.
    return 0;
}

int IsFull(CiQueue Q)
{
    if ((Q.raer + 1) % INIT_SIZE == Q.front)
    {
            //The CiQueue Q is full.
        return 1;
    }
        //The CiQueue Q is not full.
    return 0;
}

Status EnQueue(CiQueue *pQ, ElemType e)
{
    if (IsFull(*pQ))
    {
            //If the CiQueue is full, returns ERROR.
        return ERROR;
    }

    pQ->base[pQ->raer] = e;
    pQ->raer = (pQ->raer + 1) % INIT_SIZE;
    return OK;
}

Status DeQueue(CiQueue *pQ, ElemType *pe)
{
    if (IsEmpty(*pQ))
    {
            //if the CiQueue is empty, returns ERROR;
        return ERROR;
    }

    *pe = pQ->base[pQ->front];
    pQ->front = (pQ->front + 1) % INIT_SIZE;
    return OK;
}