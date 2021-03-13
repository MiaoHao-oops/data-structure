#define OK 1
    //If a funtion functions well, it would return OK.
#define ERROR 0
    //If a funtion has something wrong, it would return ERROR.
#define OVERFLOW -1
#define LIST_INIT_SIZE 100
    //LIST_INIT_SIZE is the initial size of the list.
#define LISTINCREASEMENT 10
    //LISTINCREASEMENT is the size increased when the size is not enough for using.

typedef int Status;
typedef int ElemType;   
    //The type of element is flexible, and it could even be a struct.
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
    //A SqList includes elements(elem), the length of the list(length) and the size of the list(listsize).

Status InitList(SqList *pL);
    //InitList initiates the list with size LIST_INIT_SIZE and length 0;
Status ListInsert(SqList *pL, int i, ElemType e);
    //ListInsert inserts element e as the poineer of the ith element in the list.
    //The range of i is 1 <= i <= pL->length + 1.