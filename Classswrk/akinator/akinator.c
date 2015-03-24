#include "akinator.h"

void createNode(Node **node,Info info){
    *node=(Node *)malloc(sizeof(Node));
    if(*node!=NULL){
        (*node)->info=info;
        (*node)->noLink=NULL;
        (*node)->yesLink=NULL;
    }


}

void addNewKnowlege(Node *target,Info newAnimal,Info question,bool rightYesAnswer){
    assert(target);
    Info oldAnimal=target->info;
    target->info=question;
    Node *newAnimalNode,*oldAnimalNode;
    createNode(&newAnimalNode,newAnimal);
    createNode(&oldAnimalNode,oldAnimal);
    if(rightYesAnswer){
        target->yesLink=newAnimalNode;
        target->noLink=oldAnimalNode;
    }else{
        target->yesLink=oldAnimalNode;
        target->noLink=newAnimalNode;
    }


}
Node *goToleaf (Node *root){
    assert(root);
    Node *p=root;
    while (p->info.type==questionType) {
        printf("%s\n",p->info.string);
        printf("y/n: ");
        char answer;
        scanf("%c",&answer);
        if(answer=='y'){
            p=p->yesLink;
         }else{
            p=p->noLink;
        }
    }
return p;


}
