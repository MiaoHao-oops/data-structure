#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct
{
        // base location of the array
    ElemType *base;
        // dimensions of the array
    int dim;
        // the size of each dimension b_i
    int *bounds;
        // the constant base location c_i of array mapping function
    int *constants;
}Array;

#endif