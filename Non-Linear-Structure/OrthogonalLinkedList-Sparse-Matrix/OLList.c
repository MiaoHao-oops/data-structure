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
				p = p->right;
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

Status AddMat(OSMatrix *M1, OSMatrix *M2)
{
	OLNode *p, *q, *r, *s;
	int i;
	int res;

	for (i = 0; i < M1->mu; i++)
	{
		p = M1->rhead[i];
		q = M2->rhead[i];
		
		while (p || q)
		{
			if (p && q)
			{
				res = p->data + q->data;
			}
			if (p && q && p->j == q->j && res)
			{
				p->data = res;
				p = p->right;
				q = q->right;
			}
			else if (p && (!q || p->j < q->j))
			{
				p = p->right;
			}
			else if (q && (!p || p->j > q->j))
			{
				s = (OLNode *)malloc(sizeof(OLNode));
				s->i = q->i;
				s->j = q->j;
				s->data = q->data;
				s->right = NULL;
				s->down = NULL;

				r = M1->rhead[i];
				if (r == p)
				{
					M1->rhead[i] = s;
					s->right = p;
				}
				else
				{
					while (r->right != p)
					{
						r = r->right;
					}
					s->right = r->right;
					r->right = s;
				}

				r = M1->chead[s->j];
				if (!r || r->i > s->i)
				{
					M1->chead[s->j] = s;
					s->down = r;
				}
				else
				{
					while (r->down && r->down->i < q->i)
					{
						r = r->down;
					}
					s->down = r->down;
					r->down = s;
				}

				M1->tu++;
				q = q->right;
			}
			else if (p && q && p->j == q->j && !res)
			{
				r = M1->rhead[i];
				if (r == p)
				{
					M1->rhead[i] = p->right;
					//p->right = NULL;
				}
				else
				{
					while (r->right != p)
					{
						r = r->right;
					}
					r->right = p->right;
					//p->right = NULL;
				}

				r = M1->chead[p->j];
				if (M1->chead[p->j] == p)
				{
					M1->chead[p->j] = p->down;
					//p->down = NULL;
				}
				else
				{
					while (r->down != p)
					{
						r = r->down;
					}
					r->down = p->down;
					//p->down = NULL;
				}

				M1->tu--;
				s = p->right;
				q = q->right;
				free(p);
				p = s;
			}
		}
	}

	return OK;
}