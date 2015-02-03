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
void coppyArray(int massEtalon[],int sizeN,int massCoppy[])
{
    for(int i=0; i<=sizeN; i++)
    {
        massEtalon[i]=massCoppy[i];
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
int chotny(int mass[],int sizeN,int chootnyMass[])
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

int nochotny(int mass[],int sizeN,int nochotnyMass[])
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
    for(int i=0; i<=sizeN; i++)
    {
        if(mass[i]==maxElentTransfer) mass[i]=i;
    }
}
//--------TASK4----------------
void allTransferMaxadnMin(int mass[],int sizeN,int maxChot,int minNochot)
{
    for(int i=0; i<=sizeN; i++)
    {
        if(mass[i]%2==0) mass[i]=maxChot;
        else mass[i]=minNochot;
    }
}
//--------TASK5----------------
int lastPolog(int chotnyMass[],int chotnySize,int userNumber)
{
    for(int i=chotnySize; i>=0; i--)
    {
        if(chotnyMass[i]%userNumber==0&&chotnyMass[i]>0) return i;
    }
    return -1 ;
}

int indexMass(int mass[],int sizeN,int numberChotniAndCratny)
{
    for(int i=sizeN; i>=0; i--)
    {
        if(mass[i]==numberChotniAndCratny) return i;
    }
    return -1;
}
//--------TASK6----------------
int lengzz(int mass[],int sizeN,int index)
{   int lengzz=-1;
    for(int i=index; i<=sizeN; i++)
    {   lengzz++;
        if(mass[i]!=0) return lengzz ;
    }
    return lengzz;
}

int nuli(int mass[],int sizeN,int index)
{   int lengt=-1;
    int firstIndex;
    for(int i=0;i<=sizeN;i++){

        if(mass[i]==0) {

            lengt=lengt>lengzz(mass,sizeN,i)?lengt:lengzz(mass,sizeN,i);
            firstIndex=lengt>lengzz(mass,sizeN,i)?firstIndex:i;
                i+=lengzz(mass,sizeN,i)+1;
        }
    }


  return lengt;
}
