#include"TSMatrix.h"

Status InitVec(Vector *V);
Status GetVec(Vector *V);
    /*
     * GetVec gets the element vector of a matrix
     */

int main()
{
    TSMatrix M;
    Vector V;
    int i, j;
    scanf("%d%d\n", &i, &j);
    InitMat(&M, i, j);
    InitVec(&V);
    GetVec(&V);
    GetMat(M, V);
    return 0;
}

Status InitVec(Vector *V)
{
    V->elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (!V->elem)
    {
        return OVERFLOW;
    }
    V->length = 0;
    V->size = MAXSIZE;
    return OK;
}

Status GetVec(Vector *V)
{
    char str[MAXLEN];
    int c, i;
    while(1)
    {
        i = 0;
        while ((c = getchar()) != ' ' && c != '\n' && c != EOF)
        {
            str[i++] = c;
        }
        str[i] = '\0';
        V->elem[V->length++] = atoi(str);
        if (V->length >= V->size)
        {
            V->elem = (ElemType *)realloc(V->elem, (V->size + MAXLEN) * sizeof(ElemType));
            if (!V->elem)
            {
                return OVERFLOW;
            }
            V->size += MAXLEN;
        }
        if (c == '\n' || c == EOF)
        {
            break;
        }
    }
    return OK;
}