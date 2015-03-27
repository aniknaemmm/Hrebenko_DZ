#include "akinator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char newAnimal[100], newQuestion[100], chekPravda[100];
    bool pravda;
    /*FILE *file;
    file=fopen("dataStorage.txt","r");*/
    Node *root = NULL;
    Info catInfo = {"КОТ", animalType};
    createNode(&root, catInfo);
    Node *target = NULL;

    printf("Будешь  играть?\n");

    while(chekAnswer())
    {
        system("clear");
        target = goToleaf(root);
        printf("это %s?\n", target->info.string);

        if(chekAnswer()) printf("Я угадала!\n");

        else
        {
            printf("Я не угадала!\n");
            Info newAnimalInfo;
            printf("Что это за животное? \n");
            scanf(" %s", newAnimal);
            strcpy(newAnimalInfo.string, newAnimal);
            newAnimalInfo.type = animalType;

            Info newQuestionInfo;
            printf("задай вопрос/отличие?\n");
            scanf(" %s", newQuestion);
            //fflush(stdin);
            //fgets(newQuestion,254,stdin);
            strcpy(newQuestionInfo.string, newQuestion);
            newQuestionInfo.type = questionType;
            // fflush(stdin);
            printf("правдивый ответ?\n");
            scanf(" %s", chekPravda);

            if(strcmp(chekPravda, "да") == 0) pravda = true;
            else pravda = false;

            addNewKnowlege(target, newAnimalInfo, newQuestionInfo, pravda);
            target = NULL;
        }


        printf("Будешь ещё играть?\n");
    }

    return 0;
}

