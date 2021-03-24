#include "SqStack.h"

Status InitStack(SqStack *pS)
{
    pS->base = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);
    if (!pS->base)
    {
            //The allocation is unsuceeded.
        return 0;
    }
    pS->top = 0;
    pS->stacksize = INITSIZE;
    return 1;
}

Status Push(SqStack *pS, ElemType e)
{
    if (pS->top >= pS->stacksize)
    {
            //The memory is not enough, so reallocate the moemory.
        pS->base = (ElemType *)realloc(pS->base, sizeof(ElemType) * (pS->stacksize + INCREASEMENTSIZE));
        if (!pS->base)
        {
            return 0;
        }
        pS->stacksize += INCREASEMENTSIZE;
    }

    pS->base[pS->top++] = e;
    return 1;
}

Status Pop(SqStack *pS, ElemType *pe)
{
    if (pS->top == 0)
    {
            //The case that S is empty.
        return 0;
    }
    *pe = pS->base[--pS->top];
    return 1;
}

Status GetTop(SqStack S, ElemType *pe)
{
    if (S.top == 0)
    {
            //The case that S is empty.
        return 0;
    }
    *pe = S.base[S.top];
    return 1;
}

Status IsEmpty(SqStack S)
{
    if (S.top == 0)
    {
        return 1;
    }
    return 0;
}