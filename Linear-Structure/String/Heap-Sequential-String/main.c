#include "HeString.h"

char sc[] = "Sample"; 

int main()
{
    HeString S, Subs;
    InitStr(&S);
    InitStr(&Subs);

    int lenS;
    lenS = StrLen(S);

    StrAssign(&S, sc);

    StrSubstr(S, &Subs, 5, 1);

    //StrInsert(&S, &Subs, 2);

    //StrReplace(&S, 1, 3, Subs);

    StrIndex_BF(S, Subs, 0);
    printf("%d\n", StrIndex_KMP(S, Subs, 0));
    return 0;
}