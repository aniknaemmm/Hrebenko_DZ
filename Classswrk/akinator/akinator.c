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
    char answer[256];

    do
    {
        printf("Введите да/нет\n");
        scanf(" %s", answer);

        if(strcmp("да", answer) != 0 && strcmp("нет", answer) != 0)
            printf("Только да или нет\n");
    }
    while(strcmp("да", answer) != 0 && strcmp("нет", answer) != 0);

    return strcmp("да", answer) == 0;


}
