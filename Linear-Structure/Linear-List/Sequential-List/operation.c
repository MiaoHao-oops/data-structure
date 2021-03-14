#include "SqList.h"
#include <stdlib.h>

Status InitList(SqList *pL)
{
        //pL is the pointer of SqList L.
    pL->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        //Allocate memory for elements in the list
    if (!pL->elem)
    {
            //The allocation is unsucceeded.
        exit(OVERFLOW);
    }
    pL->length = 0;
        //There is no element in the list at first.
    pL->listsize = LIST_INIT_SIZE;
        //The size of the list is the initial list size at first.
    return OK;
}

Status ListInsert(SqList *pL, int i, ElemType e)
{
    if (i < 1 || i > pL->length + 1)
    {
            //Input i is illegal.
        return ERROR;
    }
    if (pL->length >= pL->listsize)
    {
            //When allocated memery is full, reallocate and expand the memory.
        ElemType *newbase = (ElemType*)realloc(pL->elem, (pL->listsize + LISTINCREASEMENT) * sizeof(ElemType));
        if (!newbase)
        {
                //The reallocation is unsucceeded.
            exit(OVERFLOW);
        }
        pL->elem = newbase;
        pL->listsize += LISTINCREASEMENT;
    }

    ElemType *p;
    ElemType *q = &(pL->elem[i - 1]);
        //q is the addr of the insert location.

    for (p = &(pL->elem[pL->length - 1]); p >= q; p--)
    {
        *(p + 1) = *p;
            //Move the elements after q back one element.
    }
    *q = e;
        //Insert element e.
    pL->length++;
        //Increase the length of the list L.
    return OK;
}

Status ListDelete(SqList *pL, int i, ElemType e)
{
    if (i < 1 || i > pL->length)
    {
            //Input i is illegal.
        return ERROR;
    }
    ElemType *p = &(pL->elem[i - 1]);
        //p is the addr of the deleted element.
    e = *p;
    ElemType *q = &(pL->elem[pL->length - 1]);
        //q is the addr of the last element in the list.
    for (p++; p <= q; p++)
    {
        *(p - 1) = *p;
    }
    --pL->length;
        //Reduce the length of the list by 1.
    return OK;
}