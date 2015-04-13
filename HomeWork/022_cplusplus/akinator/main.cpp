#include <iostream>
#include <cstdlib>
#include <cstring>
#include "akinator.h"
using namespace std;
using namespace function;
int main(void)
{
    char newAnimal[MAX_STRING_SIZE], newQuestion[MAX_STRING_SIZE];
    bool pravda;
    FILE *file= nullptr;
    Node *root = nullptr;

    file=fopen("../Maxinator.txt","r");
    if(file==nullptr)
    {
        Info catInfo = {"КОТ", animalType};
        createNode(&root, catInfo);
    }
    else
    {
        rInfoFile(&root,file);
        fclose(file);
    }


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

            cout<<("Я не угадала!\n");
            Info newAnimalInfo;
            cout<<("Что это за животное? \n");
            fgets(newAnimal, MAX_STRING_SIZE, stdin);
            removeEndOfLine(newAnimal);
            strcpy(newAnimalInfo.string, newAnimal);
            newAnimalInfo.type = animalType;

            Info newQuestionInfo;
            cout<<("задай вопрос/отличие?\n");
            fgets(newQuestion, MAX_STRING_SIZE, stdin);
            removeEndOfLine(newQuestion);
            strcpy(newQuestionInfo.string, newQuestion);
            newQuestionInfo.type = questionType;

            cout<<("правдивый ответ?\n");
            pravda = chekAnswer();

            addNewKnowlege(target, newAnimalInfo, newQuestionInfo, pravda);
            file = fopen("../Maxinator.txt", "w");
            prefix(root,file);
            target = NULL;
            fclose(file);
        }


        cout<<"Будешь ещё играть?"<<endl;
    }








    return 0;
}

