#ifndef MYCAT_H
#define MYCAT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct MyNumb_{
    int numerator;
    int denumerator;
    int integer;
}MyNumb;

void convFractionMixed(MyNumb *data);
void convFractionNoMixed(MyNumb *data);
void enterNumber(MyNumb *data);
void showNumber(MyNumb number);
MyNumb summ(MyNumb first,MyNumb next);
MyNumb multiplication(MyNumb first,MyNumb next);
MyNumb division(MyNumb first,MyNumb next);
MyNumb subtraction(MyNumb first,MyNumb next);
int gcd(int,int);
#endif
