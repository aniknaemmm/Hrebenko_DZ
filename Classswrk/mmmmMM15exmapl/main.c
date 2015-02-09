#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("Hello world!\n");
    int mass[5][5];
    int temp;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            mass[i][j]=abs(rand()%100);
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("[%d]",mass[i][j]);
        }
        printf("\n---------------------\n");
    }
    printf("eeeeeeeeeee\n");


    for(int size=0;size<25;size++){
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {

            if(mass[i][j]>mass[i][j+1])
            {
                temp=mass[i][j];
                mass[i][j]=mass[i][j+1];
                mass[i][j+1]=temp;


            }
        }

    }
    }



    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("[%d]",mass[i][j]);
        }
        printf("\n---------------------\n");
    }
    return 0;
}
