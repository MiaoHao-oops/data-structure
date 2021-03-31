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

    StrSubstr(S, &Subs, 0, 3);
        //Subs = "Wow"

    return 0;
}