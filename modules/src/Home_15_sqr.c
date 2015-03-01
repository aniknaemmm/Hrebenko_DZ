#include <stdlib.h>
#include <stdio.h>

#include "../../modules/include/compotibility.h"
void sqr(int sizez)
{
    int sizezz=sizez;
    universalClear();
    int sizesize=1;
    while(1)
    {
        while(sizez>0)
        {
            for(int i=0; i<sizez; i++)
            {

                printf("\n");
            }

            for(int p=0; p<sizesize; p++)
            {
                printf("%*s",sizez,"");
                for(int k=0; k<sizesize; k++)
                {
                    printf("#");
                }
                printf("\n");
            }
            universalSleep(0.03);
            universalClear();

            sizez-=1;
            sizesize+=2;
        }

//universalSleep(5.0);
        while(sizezz>=sizez)
        {
            for(int i=0; i<sizez; i++)
            {

                printf("\n");
            }

            for(int p=0; p<sizesize; p++)
            {
                printf("%*s",sizez,"");
                for(int k=0; k<sizesize; k++)
                {
                    printf("#");
                }
                printf("\n");
            }
            universalSleep(0.03);
            universalClear();

            sizez+=1;
            sizesize-=2;
        }


    }

}
