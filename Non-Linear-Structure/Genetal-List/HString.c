#include "HString.h"

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

Status GetStr(HeString *S)
{
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n' && c != ' ')
    {
        S->str[i++] = c;
    }
    S->str[i] = '\0';
    S->length = i;
    return OK;
}

int StrLen(HeString S)
{
    return S.length;
}

Status IsStrEqual(HeString S, char *str)
{

    char *s, *t;
    s = S.str;
    t = str;
    while (*s == *t)
    {
            //Compare each character in each string.
        s++;
        t++;
        if (*s == '\0' || *t == '\0')
        {
            break;
        }
    }

    return (*(s) - *(t)) == 0;
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

    while (*t != '\0')
    {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';

    return OK;
}

Status SeverStr(HeString *Sub, HeString *Hsub)
{
    int i = 0, k = 0;
    char c;
    do
    {
        c = Sub->str[i++];
        if (c == '(') 
        {
            k++;
        }
        else if (c == ')')
        {
            k--;
        }
    }while (i < Sub->length && (c != ',' || k != 0));
    if (i < Sub->length)
    {
        StrSubstr(*Sub, Hsub, 0, i - 1);
        StrSubstr(*Sub, Sub, i, Sub->length - i);
    }
    else
    {
        StrAssign(Hsub, Sub->str);
        Sub->str[0] = '\0';
        Sub->length = 0;
    }
    return OK;
}