#include "OLList.h"
#include "Vector.h"

Status InitMat(OSMatrix *M, int i, int j)
{
	M->chead = NULL;
	M->rhead = NULL;
	M->mu = i;
	M->nu = j;
	M->tu = 0;
	return OK;
}

Status GetMat(OSMatrix *M)
{
	int i, j;
	int m, n;
	int Coe, vind = 0;
    Vector V;

	m = M->mu;
	n = M->nu;

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

Status PutMat(OSMatrix M)
{
	int i, j;
	int m, n, t = 0;
	OLNode *p;

	m = M.mu;
	n = M.nu;

	if (M.tu == 0)
	{
		printf("\n");
	}
	else
	{
		for (i = 0; i < m; i++)
		{
			p = M.rhead[i];
			while (p)
			{
				t++;
				if (t < M.tu)
				{
					printf("%d ", p->data);
				}
				else
				{
					printf ("%d\n", p->data);
				}
				p = p->right;
			}
		}
	}
	

	for (i = 0; i < m; i++)
	{
		p = M.rhead[i];
		for (j = 0; j < n; j++)
		{
			if (p && p->i == i && p->j == j)
			{
				if (j != n - 1)
				{
					printf ("1 ");
				}
				else
				{
					printf ("1\n");
				}
			}
			else
			{
				if (j != n - 1)
				{
					printf ("0 ");
				}
				else
				{
					printf ("0\n");
				}
			}
		}
	}
	return OK;
}
