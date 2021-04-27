#include "Array.h"

Status InitArray(Array *pA, int dim, ...)
{   
        // declare VAL ap
    va_list ap;

    if (dim < 1 || dim > MAX_ARRAY_DIM)
    {
            // illegal input dim
        return ERROR;
    }
    
    pA->dim = dim;
    pA->bounds = (int *)malloc(dim * sizeof(int));
    if (!pA->bounds)
    {
        exit(OVERFLOW);
    }

        // get the dementions for the VAL ap
    int i;
    int elemtotal = 1;
    va_start(ap, dim);
    for (i = 0; i < dim; i++)
    {
        pA->bounds[i] = va_arg(ap, int);
        if (pA->bounds[i] <= 0)
        {
            return UNDERFLOW;
        }
        elemtotal *= pA->bounds[i];
    }
    va_end(ap);

        // allotate memory for pA->base
    pA->base= (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if (!pA->base)
    {
        exit(OVERFLOW);
    }
    
        // allotate memory for pA->constant
    pA->constants = (int *)malloc(dim * sizeof(int));
    if (!pA->constants)
    {
        return OVERFLOW;
    }

        // calculate c_i and restore the result in pA->constants[i - 1]
    pA->constants[dim - 1] = 1;
    for (i = dim - 2; i >= 0; i--)
    {
        pA->constants[i] = pA->bounds[i + 1] * pA->constants[i + 1];
    }
    return OK;
}

Status Locate(Array A, va_list ap, int *off)
{
    *off = 0;

    int i, ind;
    for (i = 0; i < A.dim; i++)
    {
        ind = va_arg(ap, int);
        if (ind <= 0 || ind >= A.bounds[i])
        {
            return OVERFLOW;
        }
        *off += A.constants[i] * ind;
   }
   return OK;
}