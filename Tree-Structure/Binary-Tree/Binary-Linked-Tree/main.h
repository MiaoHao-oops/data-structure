#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef struct TNode
{
    ElemType data;
    struct TNode *left, *right;
}TNode;
typedef struct 
{
    struct TNode *root;
}BTree;

#endif