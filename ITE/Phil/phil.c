#include "phil.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
Phil *initStart()
{
    Phil *phil = NULL;

    int philx = 0;
    Phil *temp = NULL;

    while(philx++ < ALL_PHIL_NUMB)
    {
        temp = (Phil *)malloc(ALL_PHIL_NUMB * sizeof(Phil));

        if(temp == NULL)
        {
            fprintf(stderr, "error memory\n");
            exit(1);
        }

        temp->leftFork = 1;
        temp->leftHand = 0;
        temp->rightFork = 1;
        temp->rightHand = 0;

        if(philx == 1)
        {
            temp->nextPhil = temp;
            temp->linkPhil = temp;
            phil = temp;
            temp = NULL;
        }
        else
        {
            temp->nextPhil = phil->nextPhil;
            phil->nextPhil = temp;
            temp->linkPhil = phil;
            phil = temp;
            temp = NULL;
        }


        /*          2
                  1   3
                   5 4        */
    }


    return phil;
}

bool checkEat(Phil *phil)
{
    if((phil->leftFork == 0) && (phil->rightFork == 0))
        return true;

    return false;
}

bool takeFork(Phil *phil)
{
    assert(phil);

    if((phil->linkPhil->rightFork == 0) || (phil->nextPhil->leftFork == 0))
        return false;

    phil->leftHand = 1;
    phil->rightHand = 1;
    phil->leftFork = 0;
    phil->rightFork = 0;
    phil->linkPhil->rightFork = 0;
    phil->nextPhil->leftFork = 0;

    return true;
}

bool putFork(Phil *phil)
{
    assert(phil);

    if((phil->linkPhil->rightFork == 1) || (phil->nextPhil->leftFork == 1))
        return false;

    phil->leftHand = 0;
    phil->rightHand = 0;
    phil->leftFork = 1;
    phil->rightFork = 1;
    phil->linkPhil->rightFork = 1;
    phil->nextPhil->leftFork = 1;


    return true;
}




void start(Phil **tempPhil)
{
    Phil *phil = *tempPhil;

}

