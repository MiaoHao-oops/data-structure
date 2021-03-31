#include "HeString.h"

Status InitStr(HeString *pS)
{
    pS->str = (char *)malloc(INIT_SIZE * sizeof(char));
    if (!pS->str)
    {
            //The allocation is unsucceeded.
        return ERROR;
    }
    pS->size = INIT_SIZE;
    pS->length = 0;
    return OK;
}