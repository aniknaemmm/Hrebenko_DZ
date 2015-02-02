#include <stdio.h>
#include <stdlib.h>

int posledniMinus(int mass[],int sizeN)
{
    for(int i = sizeN -1; i>=0; i--)
    {
        if(mass[i]<0)
            return i;
    }

    return -1;
}



int perviiPlus(int mass[],int sizeN)
{

    for(int i=0; i<sizeN; i++)
    {
        if(mass[i]>0) return i;


    }

    return -1;
}
