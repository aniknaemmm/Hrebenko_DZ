#ifndef AKINATOR_H
#define AKINATOR_H

#include <stdbool.h>
#include <stdio.h>
#define MAX_STRING_SIZE 256

typedef enum Type_ {animalType = 1, questionType} Type;

typedef struct Info_
{
    char string[MAX_STRING_SIZE];
    Type type;

} Info;

typedef struct Node_
{
    Info info;
    struct Node_ *yesLink;
    struct Node_ *noLink;
} Node;

typedef struct Stack_
{
    Node *temp;
    struct Stack_ *link;

} Stack;


void addNewKnowlege(Node *target, Info newAnimal, Info question, bool rightAnswer);
Node *goToleaf(Node *root);
void createNode(Node **node, Info info);
bool chekAnswer();
void removeEndOfLine(char *str);
void prefix(Node *curr,FILE *ffd);
//-----
void rInfoFile(Node **root,FILE *file);
void push(Stack **stack,Node **curr);
Node *pop(Stack **stack);
void addNewNode(Node **target,Info tempInfo,bool chekWetku);
#endif // AKINATOR_H

