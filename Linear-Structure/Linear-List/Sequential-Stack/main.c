#include"SqStack.h"

int main()
{
    SqStack S;
    int a;
    InitStack(&S);
    Push(&S, 1);
    Pop(&S, &a);
    return 0;
}