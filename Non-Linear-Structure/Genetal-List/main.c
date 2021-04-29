#include "main.h"
#include "HString.h"
#include "GList.h"

int main()
{
    HeString S;
    InitStr(&S);
    GetStr(&S);

    AtomType c = getchar();
    getchar();

    GList L;
    CreateGList(&L, S);

    DelAtom(&L, c);

    if (L && !L->ptr.hp)
    {
        L = L->ptr.tp;
    }

    if (!L)
    {
        printf("-1");
        return 0;
    }
    else
    {
        putchar('(');
    }

    PutGList(L);

    // printf("%c\n", L->ptr.hp->atom);
    // printf("%d\n", L->ptr.tp->ptr.hp->type);
    return 0;    
}