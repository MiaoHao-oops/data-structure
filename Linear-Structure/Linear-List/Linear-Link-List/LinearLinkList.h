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
    LNode *next;
}LNode, *LinkList;
    //A LNode includes data and a pointer, which points to the next node.
    //Type LinkList is a pointer of LNode, and it is also called a head pointer.

Status InitList(LinkList L);
    //InitList initialized the link list.
    //After the initialization, L points to the head node of the link list.