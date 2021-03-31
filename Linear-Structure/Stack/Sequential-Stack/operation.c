#include "SqStack.h"

Status InitStack(SqStack *pS)
{
    pS->base = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);
    if (!pS->base)
    {
            //The allocation is unsuceeded.
        return ERROR;
    }
    pS->top = 0;
    pS->stacksize = INITSIZE;
    return OK;
}

Status Push(SqStack *pS, ElemType e)
{
    if (pS->top >= pS->stacksize)
    {
            //The memory is not enough, so reallocate the moemory.
        pS->base = (ElemType *)realloc(pS->base, sizeof(ElemType) * (pS->stacksize + INCREASEMENTSIZE));
        if (!pS->base)
        {
            return ERROR;
        }
        pS->stacksize += INCREASEMENTSIZE;
    }

    pS->base[pS->top++] = e;
    return OK;
}

Status Pop(SqStack *pS, ElemType *pe)
{
    if (pS->top == 0)
    {
            //The case that S is empty.
        return ERROR;
    }
    *pe = pS->base[--pS->top];
    return OK;
}

Status GetTop(SqStack S, ElemType *pe)
{
    if (S.top == 0)
    {
            //The case that S is empty.
        return ERROR;
    }
    *pe = S.base[S.top];
    return OK;
}

Status IsEmpty(SqStack S)
{
    if (S.top == 0)
    {
        return OK;
    }
    return ERROR;
}