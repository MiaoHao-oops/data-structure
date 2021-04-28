#include "main.h"
#include "OLList.h"
#include "Vector.h"

int main()
{
    Vector V;
    InitVec(&V);
    GetVec(&V);

    OSMatrix M;
    InitMat(&M);
    GetMat(&M, V);

    return 0;
}