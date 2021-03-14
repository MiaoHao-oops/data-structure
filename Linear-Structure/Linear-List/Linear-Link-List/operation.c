#include"LinearLinkList.h"
#include<stdlib.h>

Status InitList(LinkList L)
{
        //L is the head pointer of the link list.
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)
    {
            ////The allocation is unsucceeded.
        exit(OVERFLOW);
    }
    L->next = NULL;
        //Empty the link list.
        //L now points to the head node of the link list.
    return OK;
}