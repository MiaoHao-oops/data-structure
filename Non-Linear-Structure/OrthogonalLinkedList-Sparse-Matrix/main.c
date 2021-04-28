#include "main.h"
#include "OLList.h"
#include "Vector.h"

int main()
{
    int i, j;
    scanf("%d%d", &i, &j);
    getchar();
    OSMatrix M1, M2;
    InitMat(&M1, i, j);
    GetMat(&M1);
    InitMat(&M2, i, j);
    GetMat(&M2);

    PutMat(M1);

    return 0;
}