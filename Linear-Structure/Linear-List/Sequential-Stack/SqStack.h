#include<stdlib.h>
#include<stdio.h>
#define INITSIZE 100
#define INCREASEMENTSIZE 10

typedef int ElemType;
typedef int Status;
typedef struct 
{
    int top;
    ElemType *base;
    int stacksize;
}SqStack;

Status InitStack(SqStack *pS);
    //InitStack initializes the stack pS points to.
Status Push(SqStack *pS, ElemType e);
    //Push pushes element e to the top of the stack S.
Status Pop(SqStack *pS, ElemType *pe);
    //Pop pops the element on the top of the stack S, and gives it value to e.
