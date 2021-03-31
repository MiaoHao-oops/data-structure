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

#endif