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

    return OK;
}