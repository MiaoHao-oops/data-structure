#include "main.h"
#include "HString.h"
#include "GList.h"

int main()
{
    HeString S;
    InitStr(&S);
    GetStr(&S);

    GList L;
    CreateGList(&L, S);

    printf("%c\n", L->ptr.hp->atom);
    return 0;
}