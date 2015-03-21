#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int sizeList;


typedef struct DoublyNode_{
int data;
struct DoublyNode_ *next;
struct DoublyNode_ *link;
}DoubleNode;

typedef struct List_{
    DoubleNode *last;
    DoubleNode *first;
    sizeList size;
}List;

void pushFront(List **list,int data);
void dellListTwo(List **list);
void initListTwo(List **list);
int popFront(List *list);
void pushBack(List *list,int data);
int popBack(List *list);
#endif // LIST_H

