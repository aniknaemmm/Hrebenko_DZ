#include "akinator.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace function;
using namespace std;
void createNode(Node **nodes, Info info)
{
    Node *node = nullptr;
    node = new Node;

    if(node == nullptr)
    {
        fprintf(stderr, "no memory");
        exit(-1);
    }


    node->info = info;
    node->noLink = nullptr;
    node->yesLink = nullptr;
    **nodes = *node;
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
        //cout<< p->info.string <<endl;
        //printf("%s\n", p->info.string);

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
        //printf("Введите да/нет\n");
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



void prefix(Node *curr, FILE *file)
{

    if(!curr)
    {

        return;
    }

    if(file == nullptr)
    {
        fprintf(stderr, "not founded\n");
        exit(1);
    }

    if(curr->info.type == animalType)
    {
        fprintf(file , "%d %s %d\n", (int)strlen(curr->info.string), curr->info.string, curr->info.type);
    }
    else
    {
        fprintf(file , "%d %s %d\n", (int)strlen(curr->info.string), curr->info.string, curr->info.type);

    }

    prefix(curr->yesLink, file);
    prefix(curr->noLink, file);
}

void rInfoFile(Node **root, FILE *file)
{
    assert(file);
    Node *curr;
    Stack *stack = NULL;
    int strLength, typeInfo;
    Info tempInfo;
    fscanf(file, "%d ", &strLength);
    char *string = (char *)malloc(strLength * sizeof(char));
    fgets(string , strLength + 1 , file);
    fscanf(file , "%d\n" , &typeInfo);
    tempInfo.type = (Type)typeInfo;
    strcpy(tempInfo.string, string);
    createNode(&*root, tempInfo);
    push(&stack, &*root);
    curr = *root;

    while(!feof(file))
    {

        bool chekWetku;
        //Node *tempNode=NULL;
        fscanf(file, "%d ", &strLength);
        char *string = (char *)malloc(strLength * sizeof(char));
        fgets(string , strLength + 1 , file);
        fscanf(file , "%d\n" , &typeInfo);
        tempInfo.type = (Type)typeInfo;
        strcpy(tempInfo.string, string);

        if(curr->info.type == animalType)
        {
            curr = pop(&stack);
        }

        if(curr->yesLink != nullptr)
            chekWetku = false;
        else
            chekWetku = true;


        addNewNode(&curr, tempInfo, chekWetku);
        chekWetku = true;

        if(tempInfo.type == 2)
        {
            push(&stack, &curr);
        }
    }

}


void addNewNode(Node **target, Info tempInfo, bool chekWetku)
{
    Node *tempTarget = nullptr;
    createNode(&tempTarget, tempInfo);

    if(chekWetku)
    {
        (*target)->yesLink = tempTarget;
        (*target) = tempTarget;
    }
    else
    {
        (*target)->noLink = tempTarget;
        (*target) = tempTarget;
    }

}

void push(Stack **stack, Node **curr)
{
    Stack *temp = nullptr;
    temp = new Stack;

    if(temp == nullptr)
    {
        fprintf(stderr, "no memory");
        exit(-1);
    }

    temp->temp = *curr;
    temp->link = *stack;
    *stack = temp;
    temp = nullptr;
}

Node *pop(Stack **stack)
{
    Stack *tempStack = nullptr;
    Node *tempRoot = nullptr;

    if((*stack) == nullptr)
    {
        fprintf(stderr, "no stack");
        exit(-1);
    }

    tempStack = *stack;
    tempRoot = (*stack)->temp;
    *stack = (*stack)->link;
    free(tempStack);
    return tempRoot;
}
