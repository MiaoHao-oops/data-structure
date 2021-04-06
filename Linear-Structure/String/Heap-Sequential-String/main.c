#include "HeString.h"

char sc[] = "Wow"; 

int main()
{
    HeString S, Subs;
    InitStr(&S);
    InitStr(&Subs);

    int lenS;
    lenS = StrLen(S);
        //lenS = 3

    StrAssign(&S, sc);
        //S.str = "Wow"

    StrSubstr(S, &Subs, 0, 2);
        //Subs = "Wo"
    StrInsert(&S, &Subs, 2);
        //S = "WoWow"
    StrReplace(&S, 1, 3, Subs);
        //S = "WWow"
    return 0;
}