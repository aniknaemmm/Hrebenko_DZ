#ifndef TIME_H
#define TIME_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Time_{
    int hour,minut,sec;
}Time;

void enterTime(Time *data);
void showTime(Time data);
void  wtfTime(Time *data);
void addTime(Time *data);
int chekTime(Time firstTime,Time realTime);
#endif // TIME_H

