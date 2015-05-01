#define _POSIX_C_SOURCE 200809l
#include "phil.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
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

        temp->hungry    = 0;
        temp->eatPhil   = 0;
        temp->leftFork  = 1;
        temp->leftHand  = 0;
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


bool takeFork(Phil *phil)
{
    assert(phil);

    if((phil->linkPhil->rightFork == 0) || (phil->nextPhil->leftFork == 0))
        return false;

    phil->eatPhil   = 1;
    phil->leftHand  = 1;
    phil->rightHand = 1;
    phil->leftFork  = 0;
    phil->rightFork = 0;
    phil->hungry    = eatTime();
    phil->linkPhil->rightFork = 0;
    phil->nextPhil->leftFork  = 0;

    return true;
}

bool putFork(Phil *phil)
{
    assert(phil);

    if((phil->linkPhil->rightFork == 1) || (phil->nextPhil->leftFork == 1))
        return false;

    phil->eatPhil   = 0;
    phil->leftHand  = 0;
    phil->rightHand = 0;
    phil->leftFork  = 1;
    phil->rightFork = 1;
    phil->hungry    = 0;
    phil->linkPhil->rightFork = 1;
    phil->nextPhil->leftFork = 1;

    return true;
}

void start(Phil **tempPhil)
{
    Phil *phil     = *tempPhil;
    Phil *showPhil = *tempPhil;
    srand(time(NULL));

    for(;;)
    {
        sleep(1);
        system("clear");
        show(showPhil);

        for(int i = 0; i < ALL_PHIL_NUMB; i++)
        {
            if((phil->eatPhil) && phil->hungry == 0)
                putFork(phil);
            else
                phil->hungry--;

            phil = phil->nextPhil;

        }

        // sleep(1.1);

        for(int i = 0; i < ALL_PHIL_NUMB; i++)
        {
            if((phil->leftFork == 1) && (phil->rightFork == 1))
            {
                takeFork(phil);
            }

            phil = phil->nextPhil;
        }

        phil = phil->nextPhil;


    }
}

void show(Phil *phil)
{

    Phil *tempPhil = phil;

    for(int i = 0; i < ALL_PHIL_NUMB; i++)
    {
        if(tempPhil->eatPhil)
            fprintf(stderr, "1");
        else
            fprintf(stderr, "0");

        tempPhil = tempPhil->nextPhil;
    }
}

int eatTime()
{
    return rand() % 10;
}
