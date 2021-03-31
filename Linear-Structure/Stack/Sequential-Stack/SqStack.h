#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#include<stdlib.h>
#include<stdio.h>
#define INITSIZE 100
#define INCREASEMENTSIZE 10

#define OK 1
    //If a funtion functions well, it would return OK.
#define ERROR 0
    //If a funtion has something wrong, it would return ERROR.
#define OVERFLOW -1

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
Status GetTop(SqStack S, ElemType *pe);
    //GetTop gets the top element in S, and gives it value to e but not move top.
Status IsEmpty(SqStack S);

#endif