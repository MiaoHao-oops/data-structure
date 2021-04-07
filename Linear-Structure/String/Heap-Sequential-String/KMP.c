#include "HeString.h"
Status GetNext(HeString T, int next[]);

int StrIndex_KMP(HeString S, HeString T, int pos)
{
    int *next;
    next = (int *)malloc(T.length * sizeof(int));
    GetNext(T, next);
    int j, k;
    j = pos;
        //j is the main str index.
    k = 0;
        //k is the pattern str index.
    while (j < S.length && k < T.length)
    {
        if (S.str[j] == T.str[k])
        {
            j++;
            k++;
        }
        else if (k)
        {
            k = next[k - 1];
        }
        else
        {
            j++;
        }
    }
    if (k == T.length)
    {
        return j - k;
    }
    else
    {
        return -1;
    }
}

Status GetNext(HeString T, int next[])
{
    int j, k;
    j = 1;
        //j is pattern str index.
    k = 0;
        //k is match index.
    next[0] = 0;
    while (j < T.length)
    {
        if (T.str[j] == T.str[k])
        {
            next[j] = next[j - 1] + 1;
            j++;
            k++;
        }
        else if (k)
        {
            k = next[k - 1];
        }
        else
        {
                //if k == 0, the match is failed.
            next[j++] = 0;
        }
    }
    return 0;
}