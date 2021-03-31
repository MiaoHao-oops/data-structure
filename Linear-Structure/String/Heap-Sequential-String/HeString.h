#ifndef _HESTRING_H_
#define _HESTRING_H_
//Sequential string, dymanic memory allocation from the heap

#include<stdio.h>
#include<stdlib.h>

#define OK 1
    //If a funtion functions well, it would return OK.
#define ERROR 0
    //If a funtion has something wrong, it would return ERROR.
#define OVERFLOW -1
#define INIT_SIZE 100

typedef int Status;
typedef struct
{
    char *str;
    int length;
    int size;
}HeString;

Status InitStr(HeString *pS);
    //InitStr initializes the heap-sequential-string(HeString) S.
int StrLen(HeString S);
    //StrLen returns the length of HeString S.
Status IsStrEqual(HeString S1, HeString S2);
    //IsStrEqual judges whether HeString S1 is equal to S2 (returns 1), or not (returns 0).
int StrCmp(HeString S1, HeString S2);
    //StrCmp compares two HeString S1 and S2, and return the difference between them.
    
#endif