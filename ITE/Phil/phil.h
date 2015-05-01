#ifndef PHIL_H
#define PHIL_H
#define ALL_PHIL_NUMB 5
#include <stdbool.h>

typedef int NumberPhil;

typedef struct Phil_
{
    int eatPhil;
    int hungry;
    int rightFork, leftFork;
    int rightHand, leftHand;
    struct Phil_ *linkPhil, *nextPhil;
} Phil;


Phil *initStart();
Phil *addPhil();
bool takeFork(Phil *phil);
bool putFork(Phil *phil);
void start(Phil **tempPhil);
void show(Phil *phil);
int eatTime();
#endif // PHIL_H
