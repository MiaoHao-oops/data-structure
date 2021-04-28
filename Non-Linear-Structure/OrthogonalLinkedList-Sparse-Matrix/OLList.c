#include "OLList.h"
#include "Vector.h"

Status InitMat(OSMatrix *M)
{
	M->chead = NULL;
	M->rhead = NULL;
	M->mu = 0;
	M->nu = 0;
	M->tu = 0;
	return OK;
}

Status GetMat(OSMatrix *M)
{
	if (M->mu && M->nu)
	{
		return ERROR;
	}

	int i, j, Coe, vind = 0;
	int m, n;
    Vector V;

	scanf("%d%d", &m, &n);
	getchar();

	M->mu = m;
	M->nu = n;

	M->rhead = (OLink *)malloc((m + 1) * sizeof(OLink));
	M->chead = (OLink *)malloc((n + 1) * sizeof(OLink));
	if (!M->chead || !M->rhead)
	{
		exit(OVERFLOW);
	}
	for (i = 0; i < m + 1; i++)
	{
		M->rhead[i] = NULL;
	}
	for (j = 0; j < n + 1; j++)
	{
		M->chead[j] = NULL;
	}
	
    InitVec(&V);
    GetVec(&V);

	M->tu = V.length;
	OLNode *p, *q;
	for (i = 0; i < M->mu; i++)
	{
		for (j = 0; j < M->nu; j++)
		{
			scanf("%d", &Coe);
			if (Coe)
			{
				p = (OLNode *)malloc(sizeof(OLNode));
				if (!p)
				{
					exit(OVERFLOW);
				}
				if (vind > V.length - 1)
				{
					return ERROR;
				}
				p->i = i;
				p->j = j;
				p->data = V.elem[vind++];
				if (M->rhead[i] == NULL || M->rhead[i]->j > j)
				{
					p->right = M->rhead[i];
					M->rhead[i] = p;
				}
				else
				{
					for (q = M->rhead[i]; (q->right) && q->right->j < j; q = q->right)
					{
						;
					}
					p->right = q->right;
					q->right = p;
				}

				if  (M->chead[j] == NULL || M->chead[j]->i > i)
				{
					p->down = M->chead[j];
					M->chead[j] = p;
				}
				else
				{
					for (q = M->chead[j]; (q->down) && q->down->i < i; q = q->down)
					{
						;
					}
					p->down = q->down;
					q->down = p;
				}
			}
		}
	}
	getchar();

	return OK;
}
