#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    srand(time(NULL));
    printf("Hello world!\n");
    int arrays[5][5],colDvig,swapTime,arrayTemp[5];
    for(int i=0; i<5; i++)
    {
        for(int k=0; k<5; k++)
        {
            arrays[i][k]=abs(rand()%100);
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



    for(int i=0; i<5; i++)
    {
        swapTime=arrays[i][4];
        for(int k=4; k>0; k--)
        {
            arrays[i][k]=arrays[i][k-1];
        }
        arrays[i][0]=swapTime;

    }



    printf("\neeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");



    for(int i=0; i<5; i++)
    {
        for(int k=0; k<5; k++)
        {
            printf("{%d}",arrays[i][k]);
        }
        printf("\n------------\n");
    }

    for(int i=0; i<5; i++)
    {
        swapTime=arrays[i][0];
        for(int k=0; k<5; k++)
        {
            arrays[i][k]=arrays[i][k+1];
        }
        arrays[i][4]=swapTime;

    }
    printf("\neeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");



    for(int i=0; i<5; i++)
    {
        for(int k=0; k<5; k++)
        {
            printf("{%d}",arrays[i][k]);
        }
        printf("\n------------\n");
    }

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
    printf("\neeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");



    for(int i=0; i<5; i++)
    {
        for(int k=0; k<5; k++)
        {
            printf("{%d}",arrays[i][k]);
        }
        printf("\n------------\n");
    }

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

                else{
                arrays[i+1][k]=arrays[i][k];
                }
            }


        }



    printf("\neeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");



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
