#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000
#define MAXLEN 50

typedef	int Status;
typedef int ElemType;
typedef struct OLNode
{
	int i, j;
	ElemType data;
	OLNode *right, *down;
}OLNode, *OLink;
typedef struct
{
	OLink *rhead, *chead;
	int mu, nu, tu;
}OLList;
typedef struct
{
    ElemType *elem;
    int length;
    int size;
}Vector;

#endif