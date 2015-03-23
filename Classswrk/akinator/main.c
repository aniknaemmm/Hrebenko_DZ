#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define MAX_STRING_SIZE 256

typedef enum Type_{animalType=1,questionType}Type;

typedef struct Info_{
    char string[MAX_STRING_SIZE];
    Type type;

}Info;

typedef struct Node_{
    Info info;
struct Node_ *yesLink;
struct Node_ *noLink;
}Node;



//main------------------------------------------------------
void addNewKnowlege(Node *target,Info newAnimal,Info question,bool rightAnswer);
Node *goToleaf (Node *root);
void createNode(Node **node,Info info);
int main(void)
{

    Node *root=NULL;
    Info catInfo={"КОТ",animalType};
    createNode(&root,catInfo);
    Info whaleInfo={"КиТ",animalType};
    Info questionInfo={"Оно большое?",questionType};
    addNewKnowlege(root,whaleInfo,questionInfo,true);
    Node *target=goToleaf(root);
    printf("это %s?\n",target->info.string);

    return 0;
}

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
