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

Status PutGList(GList L)
{
    if (!L)
    {
        return OK;
    }
    if (L->type)
    {
        if (L->ptr.hp->type)
        {
            putchar('(');
        }
        PutGList(L->ptr.hp);
        if (L->ptr.tp)
        {
            putchar(',');
            PutGList(L->ptr.tp);
        }
        else
        {
            putchar(')');
        }        
    }
    else
    {
        putchar(L->atom);
    }
    return OK;
}

Status DelAtom(GList *L, AtomType e)
{
    GLNode *p, *head;
    if (!*L)
    {
        return OK;
    }
    head = (*L)->ptr.hp;
    if ((!head->type) && head->atom == e)
    {
        p = (*L)->ptr.tp;
        DelAtom(&p, e);
        (*L)->ptr.hp = NULL;
        free(head);
        if (p && !p->ptr.hp)
        {
            (*L)->ptr.tp = p->ptr.tp;
            free(p);            
        }
    }
    else if ((!head->type) && head->atom != e)
    {
        DelAtom(&(*L)->ptr.tp, e);
        p = (*L)->ptr.tp;
        if (p && !p->ptr.hp)
        {
            (*L)->ptr.tp = p->ptr.tp;
            free(p);
        }
    }
    else if (head->type)
    {
        DelAtom(&head, e);
        p = (*L)->ptr.hp;
        if (p && !p->ptr.hp)
        {
            (*L)->ptr.hp = p->ptr.tp;
            free(p);
        }
        DelAtom(&(*L)->ptr.tp, e);
        p = (*L)->ptr.tp;
        if (p && !p->ptr.hp)
        {
            (*L)->ptr.tp = p->ptr.tp;
            free(p);
        }
    }
    return OK;
}