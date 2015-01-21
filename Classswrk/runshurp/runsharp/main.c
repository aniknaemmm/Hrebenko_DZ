#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/compotibility.h"
#include <math.h>
int main()
{
    int position=0;
    int adding=1;
    double M_PI=3.14;
    while(1){
        for(int i=0;i<position;i++)
        {
            printf(" ");
        }
        printf("#\n\n");
        universalSleep(1.0/(sin(2* M_PI*position/39)+4.5));
        universalClear();
        if(position<0||position>=40){
            adding=-adding;
        }
        position+=adding;

        }



    return 0;
}
