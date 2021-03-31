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