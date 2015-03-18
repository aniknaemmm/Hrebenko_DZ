#include "Queue.h"
void addList(Node **list,int data){

    Node *p=NULL;
    p=(Node *)malloc(sizeof(Node));
    if(p==NULL){
        fprintf(stderr,"sss");
        exit(1);
    }
    p->data=data;
    p->link=*list;
    *list=p;
    }
void printfs(const Node *list){

    while(list){
        printf("%d ",list->data+1);
        list=list->link;
    }

}

void clears(Node **list){

    while (*list) {
       Node *p=*list;
       *list=(*list)->link;
       free(p);
    }

}
