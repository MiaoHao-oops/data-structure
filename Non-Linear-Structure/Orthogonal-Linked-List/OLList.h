#ifndef _OLLIST_H_
#define _OLLIST_H_

#include <stdio.h>
#include <stdlib.h>

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
};

#endif
