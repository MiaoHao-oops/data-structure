#include "HeString.h"

Status InitStr(HeString *pS)
{
    pS->str = (char *)malloc(INIT_SIZE * sizeof(char));
    if (!pS->str)
    {
            //The allocation is unsucceeded.
        return ERROR;
    }
    pS->str[0] = '\0';
        //Init str as an empty string
    pS->size = INIT_SIZE;
    pS->length = 0;
    return OK;
}

int StrLen(HeString S)
{
    return S.length;
}

Status IsStrEqual(HeString S1, HeString S2)
{
    if (S1.length != S2.length)
    {
        return 0;
    }

    while (*(S1.str++) == *(S2.str++))
    {
            //Compare each character in each string.
        ;
    }

    return (*(S1.str) - *(S2.str)) == 0;
}

int StrCmp(HeString S1, HeString S2)
{
    while (*(S1.str++) == *(S2.str++))
    {
            //Compare each character in each string.
        ;
    }

    return *(S1.str) - *(S2.str);
}