#include "SqList.h"

Status InitList(SqList* pL)
{
        //pL is the pointer of SqList L.
    pL->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        //Allocate memory for elements in the list
    if (!pL->elem)
    {
        exit(OVERFLOW);
            //The allocate is unsucceeded.
    }
    pL->length = 0;
        //There is no element in the list at first.
    pL->listsize = LIST_INIT_SIZE;
        //The size of the list is the initial list size at first.
    return OK;
}