#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>

typedef struct ListNode_{
    int data;
    struct ListNode_ *next;
}ListNode;

bool chekNullList(ListNode *list);
void addList(ListNode **list,int data);
void printList(ListNode *list);
void dellist(ListNode **list);
int popList(ListNode **list);
int collNode(ListNode *list);
void addNodeToEnd(ListNode **list,int data);


#endif // LIST_H
