#include "akinator.h"

int main(void)
{
    FILE *file;
    file=fopen("dataStorage.txt","r");
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

