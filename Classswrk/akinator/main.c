#include "akinator.h"

int main(void)
{   char answ,newAnimal[100],newQuestion[100];
    /*FILE *file;
    file=fopen("dataStorage.txt","r");*/
    Node *root=NULL;
    Info catInfo={"КОТ",animalType};
    createNode(&root,catInfo);
   //Info whaleInfo={"КиТ",animalType};
   //Info questionInfo={"Оно большое?",questionType};
    //addNewKnowlege(root,whaleInfo,questionInfo,true);
    Node *target=NULL;



    while(1){

            target=goToleaf(root);
            printf("это %s?",target->info.string);
            scanf(" %c",&answ);
            if(answ=='y') printf("molorik");
            else{
            Info newAnimalInfo;
            printf("kakoe givotnoe>>? ");
            scanf(" %s",newAnimal);
            strcpy(newAnimalInfo.string,newAnimal);
            newAnimalInfo.type=animalType;
            Info newQuestionInfo;
            printf("kakoi vopros>>?");
            scanf(" %s",newQuestion);
            strcpy(newQuestionInfo.string,newQuestion);
            newQuestionInfo.type=questionType;
            addNewKnowlege(target,newAnimalInfo,newQuestionInfo,true);
            target=NULL;
            }
        }




    return 0;
}

