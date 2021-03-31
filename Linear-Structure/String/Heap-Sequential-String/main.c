#include "HeString.h"

char sc[] = "Wow"; 

int main()
{
    HeString S;
    InitStr(&S);

    int lenS;
    lenS = StrLen(S);

    StrAssign(&S, sc);
    
    return 0;
}