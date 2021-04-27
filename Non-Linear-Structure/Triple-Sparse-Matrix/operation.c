#include "TSMatrix.h"

Status InitMat(TSMatrix *M, int i, int j)
{
    M->HEAD = (TNode *)malloc(sizeof(TNode));
    if (!M->HEAD)
    {
        return OVERFLOW;
    }
    M->HEAD->T.a = -1;
    M->HEAD->T.b = -1;
        // (-1, -1) is an invalid location in the matrix
    M->HEAD->T.data = 0;
    M->HEAD->next = NULL;
    M->row = i;
    M->col = j;
    return OK;
}

Status GetMat(TSMatrix M, Vector V)
{
    int Coe, vind = 0;
        // vind is the index of V.elem[]
    int i, j;
    TNode *p, *q;
    p = M.HEAD;
    for (i = 0; i < M.col; i++)
    {
        for (j = 0; j < M.col; j++)
        {
            scanf("%d", &Coe);
            if (Coe)
            {
                if (vind > V.length - 1)
                {
                    return ERROR;
                }

                q = (TNode *)malloc(sizeof(TNode));
                if (!q)
                {
                    return OVERFLOW;
                }
                q->T.a = i;
                q->T.b = j;
                q->T.data = V.elem[vind++];
                q->next = NULL;
                p->next = q;
                p = q;

                /* 
                 * sudo code:
                 * if (vind > V.length) return ERROR
                 * T = (i, j, V.elem[vind++]);
                 * Insert(TSMatrx M, Triple T, vind + 1);
                 */
            }
        }
    }
    getchar();

    return OK;
}

Status AddMat(TSMatrix M1, TSMatrix M2, TSMatrix M3)
{
    TNode *p, *q, *r, *s;
    p = M1.HEAD->next;
    q = M2.HEAD->next;
    r = M3.HEAD;
    int off1, off2, res;
    while (p && q)
    {
        off1 = p->T.a * M1.col + p->T.b;
        off2 = q->T.a * M2.col + q->T.b;
        res = p->T.data + q->T.data; 
        s = (TNode *)malloc(sizeof(TNode));
        if (!s)
        {
            return OVERFLOW;
        }
        if (off1 == off2)
        {
            if (res)
            {
                s->T = p->T;
                s->T.data = res;
                s->next = NULL;
                r->next = s;
                r = s;
            }
            p = p->next;
            q = q->next;
        }
        else if (off1 < off2)
        {
            s->T = p->T;
            s->next = NULL;
            r->next = s;
            r = s;
            p = p->next;
        }
        else if (off1 > off2)
        {
            s->T = q->T;
            s->next = NULL;
            r->next = s;
            r = s;
            q = q->next;
        }
    }

    while (p)
    {
        s = (TNode *)malloc(sizeof(TNode));
        s->T = p->T;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }

    while (q)
    {
        s = (TNode *)malloc(sizeof(TNode));
        s->T = q->T;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }

    return OK;
}

Status PutMat(TSMatrix M)
{
    if (!M.HEAD)
    {
        return ERROR;
    }
    else if (!M.HEAD->next)
    {
        printf("\n");
    }
    TNode *p;
    p = M.HEAD->next;

    if (p)
    {
        while (p->next)
        {
            printf("%d ", p->T.data);
            p = p->next;
        }
        printf("%d\n", p->T.data);
    }

    p = M.HEAD->next;
    int i, j;
    for (i = 0; i < M.row; i++)
    {
        for (j = 0; j < M.col; j++)
        {
            if (p && i == p->T.a && j == p->T.b)
            {
                if (j != M.col - 1)
                {
                    printf("1 ");
                }
                else
                {
                    printf("1\n");
                }
                p = p->next;
            }
            else
            {
                if (j != M.col - 1)
                {
                    printf("0 ");
                }
                else
                {
                    printf("0\n");
                }
            }
        }
    }

    return OK;
}