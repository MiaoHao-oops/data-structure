#ifndef _HSTRING_H_
#define _HSTRING_H_

#include "main.h"

#define INIT_SIZE 100

Status InitStr(HeString *S);
    //InitStr initializes the heap-sequential-string(HeString) S.

Status GetStr(HeString *S);
    /*
     * GetStr functions as follows:
     * input a string from the input stream
     * set the length of S
     */

int StrLen(HeString S);
    //StrLen returns the length of HeString S.

Status IsStrEqual(HeString S, char* str);
    /*
     * IsStrEqual functions as follows:
     * if HeString S is equal to a constant string str, returns 1
     * else returns 0
     */

Status StrSubstr(HeString S, HeString *Subs, int i, int j);
    //Take the substring and put the consecutive j characters in S starting from the i-th character into Subs.
    //The index begins from 0.

Status StrAssign(HeString *pS, char *sc);
    //StrAssign copies the const string sc to HeString S.

Status SeverStr(HeString *Sub, HeString *Hsub);

#endif