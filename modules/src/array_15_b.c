#include "../include/array_15_b.h"
#include "../include/liner_rnd.h"
//-------other--------------
void randomArray(int mass[],int sizeN)
{
    for(int i=0; i<=sizeN; i++)
    {
        mass[i]=rand()%100;
    }

}
//-------TASK1-------------
int firstPlus(int mass[],int sizeN)
{
    for(int i = 0; i<=sizeN; i++)
    {
        if(mass[i]>0) return i;
    }
    return -1;
}


int lastMinus(int mass[],int sizeN)
{

    for(int i = sizeN ; i>=0; i--)
    {
        if(mass[i]<0) return i;
    }
    return -1;
}

void transfer(int mass[],int indexMinus, int indexPlus)
{
    int temp;
    temp=mass[indexMinus];
    mass[indexMinus]=mass[indexPlus];
    mass[indexPlus]=temp;

}

//------TASK2----------------------
int chotny(int mass[],int sizeN)
{
    int nwsize=-1;
    for(int i=0; i<=sizeN; i++)
    {
        if(mass[i]%2==0)
        {
            ++nwsize;
            chootnyMass[nwsize]=mass[i];
        }
    }

    return nwsize;
}



int nochotny(int mass[],int sizeN)
{
    int nwsize=-1;
    for(int i=0; i<=sizeN; i++)
    {
        if(mass[i]%2!=0)
        {
            ++nwsize;
            nochotnyMass[nwsize]=mass[i];
        }
    }
    return nwsize;
}



int maxNumberArray(int mass[],int n)
{
    int tempMax=mass[0];
    for(int i=0; i<=n; i++)
    {
        tempMax=mass[i]>tempMax?mass[i]:tempMax;
    }
    return tempMax ;
}


int minNumberArray(int mass[],int n)
{
    int tempMax=mass[0];
    for(int i=0; i<=n; i++)
    {
        tempMax=mass[i]<tempMax?mass[i]:tempMax;
    }
    return tempMax ;
}

//--------TASK3----------------
void maxTransferIndex(int mass[],int sizeN,int maxElentTransfer)
{
    for(int i=0; i<=sizeN;i++)
    {
        if(mass[i]==maxElentTransfer) mass[i]=i;
    }
}
