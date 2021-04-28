#include"TSMatrix.h"

Status InitVec(Vector *V);
Status GetVec(Vector *V);
    /*
     * GetVec gets the element vector of a matrix
     */

int main()
{
    TSMatrix M1, M2, M3;
    Vector V1, V2;
    int i, j;
    scanf("%d%d\n", &i, &j);
    InitMat(&M1, i, j);
    InitVec(&V1);
    GetVec(&V1);
    GetMat(M1, V1);

    InitMat(&M2, i, j);
    InitVec(&V2);
    GetVec(&V2);
    GetMat(M2, V2);

    InitMat(&M3, i, j);

    AddMat(M1, M2, M3);

    PutMat(M3);

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
    if (!V->elem[0])
    {
        V->length--;
    }
    return OK;
}