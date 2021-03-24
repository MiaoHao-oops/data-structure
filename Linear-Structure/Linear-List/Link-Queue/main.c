#include "LinQueue.h"

int main()
{
    LQueue Q;
    ElemType e;
    InitQueue(&Q);
    EnQueue(Q, 1);
    DeQueue(Q, &e);
    return 0;
}