#include "textEditor.h"

#include <stdlib.h>
#include <stdio.h>
Node **initListTextEditor()
{
    Node **tempList=NULL;
    tempList=(Node **)malloc(2*sizeof(Node *));
    if(tempList==NULL)
    {
        fprintf(stderr,"errr memory");
        exit(-2);
    }
    tempList[0]=NULL;
    tempList[1]=NULL;

    return tempList;

}

void addNode(Node **list,int data){
    Node *p=NULL;
    p=(Node *)malloc(sizeof(Node));
    if(p==NULL){
        exit(-2);

    }
     p->position=data;
     p->link=*list;
     *list=p;
}
