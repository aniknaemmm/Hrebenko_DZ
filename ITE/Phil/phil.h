#ifndef PHIL_H
#define PHIL_H
#define ALL_PHIL_NUMB 5
#include <stdbool.h>

typedef int NumberPhil;

typedef struct Phil_
{
    NumberPhil numberPhil;
    int *rightFork, *leftFork;
    int *rightHand, *leftHand;
    struct Phil_ *linkPhil, *nextPhil;
} Phil;


Phil *initStart();
Phil *addPhil();

#endif // PHIL_H
