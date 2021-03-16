#define OK 1
    //If a funtion functions well, it would return OK.
#define ERROR 0
    //If a funtion has something wrong, it would return ERROR.
#define OVERFLOW -1

typedef int Status;
typedef int Elemtype;
typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
}LNode, *LinkList;
    //A LNode includes data and a pointer, which points to the next node.
    //Type LinkList is a pointer of LNode, and it is also called a head pointer.

Status InitList(LinkList *pL);
    //InitList initialized the link list.
    //After the initialization, L points to the head node of the link list.
int ListLength(LinkList L);
    //ListLength returns the length of the link list L.
Status ListInsert(LinkList L, int i, Elemtype e);
    //ListInsert inserts element e as the poineer of the ith element in the list.
    //The range of i is 1 <= i <= ListLength(L) + 1.
Status ListDele(LinkList L, int i);
    //ListDelete deletes the ith node in the list.
Status DestoryList(LinkList *pL);
    //DeatoryList destories the existing list.
    //If the list has not been initialized, the function would return ERROR.