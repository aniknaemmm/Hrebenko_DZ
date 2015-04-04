#include "list.h"

void initListTwo(List **list){
List *temp=(List*)malloc(sizeof(List));
temp->size=0;
temp->last=temp->first=NULL;
*list=temp;
}


void dellListTwo(List **list){
    DoubleNode *temp=(*list)->first;
    DoubleNode *next=NULL;
      while(temp){
            next=temp->link;
            free(temp);
            temp=next;
}
    free(*list);
    *list=NULL;
}

void pushFront(List **list,int data){
    DoubleNode *temp=(DoubleNode *)malloc(sizeof(DoubleNode));
        if(temp==NULL)
            exit(-1);
        temp->data=data;
        temp->next=NULL;
        temp->link=(*list)->first;
        if((*list)->first)
            (*list)->first->next=temp;
        (*list)->first=temp;
        if((*list)->last==NULL)
            (*list)->last=temp;
        (*list)->size++;
    temp=NULL;
}

int popFront(List *list){
    DoubleNode *temp;
    int tempc;
    if(list->first==NULL)
        exit(2);
    temp=list->first;
    list->first=list->first->link;
    if(list->first)
        list->first->next=NULL;
    if(temp==list->last)
        list->last=NULL;
    tempc=temp->data;
    free(temp);
    list->size--;
    temp=NULL;
    return tempc;
}

void pushBack(List *list,int data){
    DoubleNode *tempNode=(DoubleNode *)malloc(sizeof(DoubleNode));
    if(tempNode==NULL)
        exit(-1);
    tempNode->data=data;
    tempNode->link=NULL;
    tempNode->next=list->last;
    if(list->last)
    list->last->link=tempNode;
    list->last=tempNode;
    if(list->first==NULL)
        list->first=tempNode;
    list->size++;
    tempNode=NULL;
}

int popBack(List *list){
    DoubleNode *temp;
    int value;
    if(list->last==NULL)
    exit(2);
    temp=list->last;
    list->last=list->last->next;
    if(list->last)
        list->last->link=NULL;
    if(temp==list->first)
        list->first=NULL;
    value=temp->data;
    free(temp);
    list->size--;
    temp=NULL;
    return value;
}
