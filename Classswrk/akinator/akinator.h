#ifndef AKINATOR_H
#define AKINATOR_H

#include <stdbool.h>

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



void addNewKnowlege(Node *target, Info newAnimal, Info question, bool rightAnswer);
Node *goToleaf(Node *root);
void createNode(Node **node, Info info);
bool chekAnswer();
void removeEndOfLine(char *str);

#endif // AKINATOR_H

