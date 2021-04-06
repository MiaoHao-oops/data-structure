#ifndef _HESTRING_H_
#define _HESTRING_H_
//Sequential string, dymanic memory allocation from the heap

#include<stdio.h>
#include<stdlib.h>

#define OK 1
    //If a funtion functions well, it would return OK.
#define ERROR 0
    //If a funtion has something wrong, it would return ERROR.
#define OVERFLOW -1
#define INIT_SIZE 100

typedef int Status;
typedef struct
{  
    char *str;
        //The index of str begins with 0.
    int length;
        //The end character '\0' is not included.
    int size;
        //The end character '\0' is included in size.
}HeString;

Status InitStr(HeString *pS);
    //InitStr initializes the heap-sequential-string(HeString) S.

int StrLen(HeString S);
    //StrLen returns the length of HeString S.

Status IsStrEqual(HeString S1, HeString S2);
    //IsStrEqual judges whether HeString S1 is equal to S2 (returns 1), or not (returns 0).

int StrCmp(HeString S1, HeString S2);
    //StrCmp compares two HeString S1 and S2, and return the difference between them.

Status StrAssign(HeString *pS, char *sc);
    //StrAssign copies the const string sc to HeString S.

Status StrSubstr(HeString S, HeString *pSubs, int i, int j);
    //Take the substring and put the consecutive j characters in S starting from the i-th character into Subs.
    //The index begins from 0.

Status StrInsert(HeString *pS, HeString *pT, int i);
    //StrInsert insert HeString T before the i-th character in HeString S.

Status StrReplace(HeString *pS, int i, int j, HeString T);
    //StrReplace replaces the exceeding j characters beginning at the i-th character in S with T.
    //0 <= i <= pS->length - 1
    //1 <= j <= pS->length - i
#endif