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
Status ListDelete(SqList *pL, int i, ElemType e);
    //ListDelete deletes the ith element in the list, and e carries the value of the deleted element.
    //The range of i is 1 <= i <= pL->length.
int LocateElem(SqList *pL, ElemType e, Status (*comp)(const ElemType a, const ElemType b));
    //LocateElem locates element e in the list.
    //It returns the location of the element firstly satisfy comp(e, pL->elem[i]).
    //If element e is not in the list, it returns ERROR.
    //comp is a function which could compare elem a and b, and returns a status code.