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

Status StrAssign(HeString *pS, char *sc)
{
    int lenSC = 0;
    while (sc[lenSC])
    {
            //Cauculate the length of sc
        lenSC++;
    }

    if (lenSC >= pS->size)
    {
        pS->str = (char *)realloc(pS->str, (lenSC + 1) * sizeof(char));
        if (!pS->str)
        {
                //The allocation is unsucceeded.
            return ERROR;
        }

        pS->size = lenSC + 1;
    }

    pS->length = lenSC;

    char *s, *t;

    s = pS->str;
    t = sc;

    while (*s++ = *t++)
    {
        ;
    }

    return OK;
}
Status StrSubstr(HeString S, HeString *pSubs, int i, int j)
{
    if (i < 0 || i >= S.length || j < 0 || i + j - 1 >= S.length)
    {
            //illegal input, out of range
        return ERROR;
    }

    char *s, *t;
    int k = 0;
    s = S.str + i;
    t = pSubs->str;
    while (k < j)
    {
        *t++ = *s++;
        k++;
    }
    *t = '\0';
    pSubs->length = j;
    return 0;
}

Status StrInsert(HeString *pS, HeString *pT, int i)
{
    if (i < 0 || i > pS->length)
    {
            //illegal input i
        return ERROR;
    }

    if (pS->length + pT->length >= pS->size)
    {
        pS->str = (char *)realloc(pS->str, (pS->length + pT->length + 1) * sizeof(char));
        if (!pS->str)
        {
            return ERROR;
        }
        pS->size = pS->length + pT->length + 1;
    }
    

    int j;
    for (j = pS->length; j >= i; j--)
    {
        pS->str[j + pT->length] = pS->str[j];
    }
    for (j = 0; j <= pT->length - 1; j++)
    {
        pS->str[j + i] = pT->str[j];
    }
    
    pS->length = pS->length + pT->length;

    return OK;
}

Status StrReplace(HeString *pS, int i, int j, HeString T)
{
    int k;
    if (i < 0 || i > pS->length - 1 || j < 1 || j > pS->length - i)
    {
            //illegal input
        return ERROR;
    }
    if (j < T.length)
    {
        if (pS->length  + T.length - j >= pS->size)
        {
            pS->str = (char *)realloc(pS->str, (pS->length + T.length - j + 1) * sizeof(char));
            if (!pS->str)
            {
                    //unsuccessful allocation
                return ERROR;
            }
            pS->size = pS->length + T.length - j + 1;
        }
        for (k = pS->length - 1; k > i + j - 1; k--)
        {
            pS->str[k + T.length - j] = pS->str[k];
        }
    }
    else
    {
        for (k = i + j; k < pS->length; k++)
        {
            pS->str[k + T.length - j] = pS->str[k];
        }
    }

    pS->length = pS->length + T.length - j;
    pS->str[pS->length] = '\0';
    for (k = 0; k < T.length; k++)
    {
        pS->str[k + i] = T.str[k];
    }
    return OK;
}