#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>


enum flags{chek,chekout};

typedef struct Node_{
    int data;
    struct Node_ *link;
}Node;

void addList(Node **list,int data);
void printfs(const Node *list);
void clears(Node **list);
#endif // QUEUE_H
