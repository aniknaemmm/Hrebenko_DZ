#include "../include/liner_rnd.h"
void arrayRand(int mass[],int userNumberSizeArray)
{
    for(int i=0; i<userNumberSizeArray; i++)
    {
        mass[i]=rand()%101+1;
    }

}

int arrayMax(int mass[],int userNumberSizeArray)
{
    int rez=mass[0];
    for(int i=0; i<userNumberSizeArray; i++)
    {
        if(rez<mass[i]) rez=mass[i];
    }

    return rez;
}

int arrayMin(int mass[],int userNumberSizeArray)
{
    int rez=mass[0];
    for(int i=1; i<userNumberSizeArray; i++)
    {
        if(rez>mass[i]) rez=mass[i];
    }

    return rez;
}
