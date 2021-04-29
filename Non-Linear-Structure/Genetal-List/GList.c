#include "GList.h"
#include "HString.h"

Status CreateGList(GList *L, HeString S)
{
    GLNode *p, *q;
    HeString SubS, Hsub;

    InitStr(&SubS);
    InitStr(&Hsub);
    
    if (IsStrEqual(S, "()"))
    {
        *L = NULL;
    }
    else
    {
        *L = (GList)malloc(sizeof(GLNode));
        if (!*L)
        {
            exit(OVERFLOW);
        }
        if (StrLen(S) == 1)
        {
            (*L)->type = ATOM;
            (*L)->atom = S.str[0];
        }
        else
        {
            (*L)->type = LIST;
            p = *L;
            StrSubstr(S, &SubS, 1, S.length - 2);

            do
            {
                SeverStr(&SubS, &Hsub);
                CreateGList(&p->ptr.hp, Hsub);
                q = p;
                if (SubS.length)
                {
                    p = (GLNode *)malloc(sizeof(GLNode));
                    if (!p)
                    {
                        exit(OVERFLOW);
                    }
                    p->type = LIST;
                    q->ptr.tp = p;
                }
            }while(SubS.length);
            q->ptr.tp = NULL;
        }
    }

    return OK;
}