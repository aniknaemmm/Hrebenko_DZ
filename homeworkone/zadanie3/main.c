#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int height,rad;
    double area,vol;
    double pi=3.1415926535;
    printf("enter height:");
    scanf("%d",&height);
    printf("enter radius:");
    scanf("%d",&rad);
    vol=(pi*rad*rad*height)/3;
    area=pi*rad*sqrt(rad*rad+height*height);
    printf("Ploshad poverxnosti S=%.5f\n",area);
    printf("Ob'om konusa raven  V=%.5f\n",vol);
    return 0;
}
