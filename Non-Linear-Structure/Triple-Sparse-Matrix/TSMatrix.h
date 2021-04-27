#ifndef _TSMATRIX_H_
#define _TSMATRIX_H_

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000
#define MAXLEN 50

typedef int Status;
typedef int ElemType;
typedef struct
{
    int a, b;
    ElemType data;
}Triple;
typedef struct TNode
{
    Triple T;
    struct TNode *next;
}TNode;
typedef struct
{
    ElemType *elem;
    int length;
    int size;
}Vector;
    /*
     * Vector is a sequential list
     */
typedef struct
{
    int row, col;
    TNode *HEAD;
}TSMatrix;
    /*
     * TSMatrix is a linked list makeup with Triples
     * row and col indicate the size of TSMAtrix
     * a head node pointer HEAD is included
     */

Status InitMat(TSMatrix *M, int i, int j);
    /*
     * InitMat functions as follows:
     * allocate an empty node as the head node of the list
     * assign the size of M, row = i, col = j
     */

Status GetMat(TSMatrix M, Vector V);
    /*
     * GetMat functions as follows:
     * M is an empty matrix
     * input the element not equal to 0 as a vertor V=[x1, x2, ..., xn], where n is unkonwn
     * input a 0-1 matrix to locate the elements in order
     * establish the linked list
     */

#endif