#include"LinearLinkList.h"
#include<stdlib.h>

Status InitList(LinkList *pL)
{
        //L is the head pointer of the link list.
    *pL = (LNode*)malloc(sizeof(LNode));
    if (!*pL)
    {
            ////The allocation is unsucceeded.
        exit(OVERFLOW);
    }
    (*pL)->next = NULL;
        //Empty the link list.
        //L now points to the head node of the link list.
    return OK;
}