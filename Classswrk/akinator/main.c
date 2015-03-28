#include "akinator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char newAnimal[MAX_STRING_SIZE], newQuestion[MAX_STRING_SIZE];
    bool pravda;
    FILE *file=NULL;
    Node *root = NULL;

    file=fopen("../Maxinator.txt","r");
   // if(file==NULL)
   // {
        Info catInfo = {"КОТ", animalType};
        createNode(&root, catInfo);
    //}
   // else
    //{

    fclose(file);
    //}


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

            file = fopen("../Maxinator.txt", "w");
            printf("Я не угадала!\n");
            Info newAnimalInfo;
            printf("Что это за животное? \n");
            //scanf(" %s", newAnimal);
            fgets(newAnimal, MAX_STRING_SIZE, stdin);
            removeEndOfLine(newAnimal);
            strcpy(newAnimalInfo.string, newAnimal);
            newAnimalInfo.type = animalType;

            Info newQuestionInfo;
            printf("задай вопрос/отличие?\n");
            //scanf(" %s", newQuestion);
            //fflush(stdin);
            fgets(newQuestion, MAX_STRING_SIZE, stdin);
            removeEndOfLine(newQuestion);
            strcpy(newQuestionInfo.string, newQuestion);
            newQuestionInfo.type = questionType;
            // fflush(stdin);

            printf("правдивый ответ?\n");
            pravda = chekAnswer();

            addNewKnowlege(target, newAnimalInfo, newQuestionInfo, pravda);
            prefix(root,file);
            target = NULL;
            fclose(file);
        }


        printf("Будешь ещё играть?\n");
    }








    return 0;
}

