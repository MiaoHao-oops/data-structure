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

#define MAX_ARRAY_DIM 10

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

Status InitArray(Array *pA, int dim, ...);
    /* 
     * InitArray functions as follows:
     * allocate memory for the array
     * the size of each demension is transfered by the VAL ...
     * calculate constants 
     */

Status Assign(Array A, ElemType e, ...);
    /*
     * Assign functions as follows:
     * input the absolute location of an element
     * gives the value of e to the element in A, to which the absolute address refers to
     */

Status Locate(Array A, va_list ap, int *off);
    /*
     * Locate functions as follows:
     * get the absolute location of an element from the VAL ap
     * return the offset of the element by passing the argument *off
     * if the indexes are legal, returns OK
     * else returns OVERFLOW
     */

Status Value(Array A, ElemType *e, ...);
    /*
     * Value functions as follows:
     * input the absolute location of an element
     * gives the value of the element with the absolute location to e
     */
#endif