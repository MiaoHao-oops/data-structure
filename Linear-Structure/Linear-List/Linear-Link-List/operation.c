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

int ListLength(LinkList L)
{
    int len = 0;
        //len is the length of the link list L.
    LNode *p;
    p = L;
        //p is a pointer pointing to the node in L.
    while (p->next)
    {
            //If p does not points to the last node in L, len++ and p moves forward.
        len++;
        p = p->next;
    }
    return len;
}

Status ListInsert(LinkList L, int i, Elemtype e)
{
    int j = 0;
    LNode *p;
    p = L;
    while (p && j < i - 1)
    {
            //Move p to the (i - 1)th node in the list.
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
            //The input i is illegal.
        return ERROR;
    }

    LNode *s;
        //s points to the new node inserted in the list.
    s = (LNode*)malloc(sizeof(LNode));
    if (!s)
    {
        exit(OVERFLOW);
    }
    s->next = p->next;
    p->next = s;
    return OK;    
}