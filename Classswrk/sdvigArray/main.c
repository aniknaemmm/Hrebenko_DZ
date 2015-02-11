#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZEMASS 100


void outt(int mass[][SIZEMASS],int size,int sized);
void siftleft(int mass[][SIZEMASS],int size,int sized);
int main()

{
    srand(time(NULL));
    printf("Hello world!\n");
    int arrays[SIZEMASS][SIZEMASS],colDvig,swapTime,arrayTemp[SIZEMASS];
    int sizeFir,sizeNex;
    printf("vvedite razmer");
    scanf("%d%d",&sizeFir,&sizeNex);


    siftleft(arrays,sizeFir,sizeNex);



    outt(arrays,sizeFir,sizeNex);


    for(int i=0; i<5; i++)
    {
        swapTime=arrays[i][4];
        for(int k=4; k>0; k--)
        {
            arrays[i][k]=arrays[i][k-1];
        }
        arrays[i][0]=swapTime;

    }






    outt(arrays,5,5);

    for(int i=0; i<5; i++)
    {
        swapTime=arrays[i][0];
        for(int k=0; k<5; k++)
        {
            arrays[i][k]=arrays[i][k+1];
        }
        arrays[i][4]=swapTime;

    }




    outt(arrays,5,5);
    for(int i=0; i<6; i++)
    {

        for(int k=0; k<5; k++)
        {
            if(i==0)
            {
                arrayTemp[k]=arrays[i][k];

            }
            else if(i==5)
            {
                arrays[4][k]=arrayTemp[k];
            }
            else
            {
                arrays[i-1][k]=arrays[i][k];

            }


        }


    }



    outt(arrays,5,5);

    for(int i=4; i>=-1; i--)
    {

        for(int k=0; k<5; k++)
        {
            if(i==4)
            {
                arrayTemp[k]=arrays[i][k];

            }
            else if(i==-1)
            {
                arrays[0][k]=arrayTemp[k];
            }

            else
            {
                arrays[i+1][k]=arrays[i][k];
            }
        }


    }







    for(int i=0; i<5; i++)
    {
        for(int k=0; k<5; k++)
        {
            printf("{%d}",arrays[i][k]);
        }
        printf("\n------------\n");
    }



    return 0;
}
/*

void outt(int mass[][SIZEMASS],int size,int sized)
{
    printf("\n___________________________________\n");
    for(int i=0; i<size; i++)
    {
        for(int k=0; k<sized; k++)
        {
            printf("{%d}",mass[size][sized]);
        }
        printf("\n------------\n");
    }
    printf("\n------------------------------------\n");
}
void siftleft(int arrays[][SIZEMASS],int size,int sized){
 for(int i=0; i<size; i++)
    {
        for(int k=0; k<sized; k++)
        {
            arrays[i][k]=abs(rand()%100);
        }
    }

outt(arrays,size,sized);
}*/
