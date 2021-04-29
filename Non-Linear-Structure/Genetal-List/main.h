#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef enum {ATOM, LIST} ElemTag;
typedef char AtomType;
typedef struct GLNode
{
    ElemTag type;
    union 
    {
        AtomType atom;	          
        struct{struct GLNode *hp, *tp;} ptr;
    };
}GLNode, *GList;
typedef struct
{  
    char *str;
    int length;
    int size;
}HeString;

#endif