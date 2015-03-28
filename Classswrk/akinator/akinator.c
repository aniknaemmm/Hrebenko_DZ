#include "akinator.h"
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void createNode(Node **node, Info info)
{
    *node = (Node *)malloc(sizeof(Node));

    if(*node == NULL)
    {
        fprintf(stderr, "no memory");
        exit(-1);
    }

    if(*node != NULL)
    {
        (*node)->info = info;
        (*node)->noLink = NULL;
        (*node)->yesLink = NULL;
    }


}

void addNewKnowlege(Node *target, Info newAnimal, Info question, bool rightYesAnswer)
{
    assert(target);
    Info oldAnimal = target->info;
    target->info = question;
    Node *newAnimalNode, *oldAnimalNode;
    createNode(&newAnimalNode, newAnimal);
    createNode(&oldAnimalNode, oldAnimal);

    if(rightYesAnswer)
    {
        target->yesLink = newAnimalNode;
        target->noLink = oldAnimalNode;
    }
    else
    {
        target->yesLink = oldAnimalNode;
        target->noLink = newAnimalNode;
    }


}
Node *goToleaf(Node *root)
{
    assert(root);
    Node *p = root;

    while(p->info.type == questionType)
    {
        printf("%s\n", p->info.string);

        if(chekAnswer())
        {
            p = p->yesLink;
        }
        else
        {
            p = p->noLink;
        }
    }

    return p;


}

bool chekAnswer()
{
    char answer[MAX_STRING_SIZE];

    do
    {
        printf("Введите да/нет\n");
        fgets(answer, MAX_STRING_SIZE, stdin);
        removeEndOfLine(answer);

        if(strcmp("да", answer) != 0 && strcmp("нет", answer) != 0)
            printf("Только да или нет\n");
    }
    while(strcmp("да", answer) != 0 && strcmp("нет", answer) != 0);

    return strcmp("да", answer) == 0;
}

void removeEndOfLine(char *str)
{
    int len = strlen(str);

    if(str[len - 1] == '\n')
        str[len - 1] = '\0';
}



void prefix(Node *curr,FILE *file)
{

    if (!curr){

        return;
    }



    if(file==NULL)
    {
        fprintf(stderr, "not founded\n");
        exit(1);
    }
    if(curr->info.type==animalType)
    {
        fprintf( file ,"%d %s %d\n",(int)strlen(curr->info.string),curr->info.string,curr->info.type);
    }
    else
    {
        fprintf( file ,"%d %s %d\n",(int)strlen(curr->info.string),curr->info.string,curr->info.type );


    }
    prefix(curr->yesLink,file);
    prefix(curr->noLink,file);
}

void rInfoFile(Node *root)
{
    Node *curr=root;
}

void push(Stack **stack,Node *curr)
{
   Stack *temp=(Stack *)malloc(sizeof(Stack));
   if(temp==NULL){
       fprintf(stderr,"no memory");
       exit(-1);
   }
   temp->temp=curr;
   (*stack)->link=*stack;
   *stack=temp;
   temp=NULL;
}

Node *pop(Stack **stack)
{
    Stack *tempStack=NULL;
    Node *tempRoot=NULL;
    if((*stack)==NULL)
    {
        fprintf(stderr,"no stack");
        exit(-1);
    }
    tempStack=*stack;
    tempRoot=(*stack)->temp;
    *stack=(*stack)->link;
    free(tempStack);
    return tempRoot;
}
