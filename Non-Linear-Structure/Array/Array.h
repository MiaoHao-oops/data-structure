#ifndef _ARRAY_H_
#define _ARRAY_H_

    // include stdarg.h to use variable arguments list(VAL)
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define UNDERFLOW -1
#define OVERFLOW -2

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

Status InitArray(Array *A, int dim, ...);
    /* InitArray functions as follows:
     * allocate memory for the array
     * the size of each demension is transfered by the VAL ...
     * calculate constants 
     */

#endif