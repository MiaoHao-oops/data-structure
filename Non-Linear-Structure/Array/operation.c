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

    pA->base= (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if (!pA->base)
    {
        exit(OVERFLOW);
    }
    
    pA->constants = (int *)malloc(dim * sizeof(int));
    if (!pA->constants)
    {
        return OVERFLOW;
    }
    pA->constants[dim - 1] = 1;
    for (i = dim - 2; i >= 0; i--)
    {
        pA->constants[i] = pA->bounds[i + 1] * pA->constants[i + 1];
    }
    return OK;
}