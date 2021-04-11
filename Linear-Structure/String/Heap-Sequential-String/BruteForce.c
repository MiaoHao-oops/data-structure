#include "HeString.h"

int StrIndex_BF(HeString S, HeString T, int pos)
{
    if(!T.length)
    {
            //T cannot be empty.
        return -1;
    }
    int i;
    HeString Subs;
    InitStr(&Subs);
    for (i = pos; i < S.length - T.length + 1; i++)
    {
        StrSubstr(S, &Subs, i, T.length);
        if (IsStrEqual(T, Subs))
        {
            return i;
        }
    }
    return -1;
}