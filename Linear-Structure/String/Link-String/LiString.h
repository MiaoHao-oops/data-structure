#ifndef _LISTRING_H_
#define _LISTRING_H_
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define NODE_SIZE 10

typedef int Status;
typedef struct LSNode
{
    char str[NODE_SIZE];
    struct LSNode *next;
}LSNode;
typedef struct 
{
    LSNode *data;
    int length;
    int size;
}LiString;

#endif