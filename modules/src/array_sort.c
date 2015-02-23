#include <stdio.h>

void randInArray(int arraY[],int sizeN)
{
    for(int i=0; i<sizeN; i++)
    {
        arraY[i]=rand()%100;
    }
}
void showArrayint (int arraY[],int sizeN)
{
    for(int i=0; i<sizeN; i++)
    {
        printf("[%d]",arraY[i]);
    }
    printf("\n");
}


void selectionSort(int arraY[],int sizeN)
{
    int min,temp;
    for(int i=0; i<sizeN; i++)
    {
        min=i;
        for(int k=i+1; k<sizeN; k++)
        {
            if(arraY[min]>arraY[k]) min=k;
        }
        if(i!=min)
        {
            temp=arraY[i];
            arraY[i]=arraY[min];
            arraY[min]=temp;
        }
    }
}

void  bubbleSort(int arraY[],int sizeN)
{
    int temp;
    for(int i=0; i<sizeN; i++)
    {
        for(int k=0; k<sizeN; k++)
        {
            if(arraY[i]<arraY[k])
            {
                {
                    temp=arraY[i];
                    arraY[i]=arraY[k];
                    arraY[k]=temp;
                }
            }
        }
    }


}
