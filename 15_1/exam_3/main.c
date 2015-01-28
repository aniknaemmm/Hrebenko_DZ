#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/arr_15_1.h"
#include "../../modules/include/array_15_max_min.h"
#include "../../modules/include/compotibility.h"
#include "../../modules/include/liner_rnd.h"
#define N 90
int main()
{
    int mass[N];
    int userNumberSizeArray;
    int userTupak=1;
    printf("hello\n vedite razmer massiva (ot 1 do 90) ");
    scanf("%d",&userNumberSizeArray);
    while(userNumberSizeArray<1||userNumberSizeArray>90){
        universalClear();
        printf("error\n");
        printf("vedite razmer massiva !!!!!>(ot 1 do 90) ");
        scanf("%d",&userNumberSizeArray);
        userTupak++;
        if(userTupak==3) exit(127);
    }
    arrayRand(mass,userNumberSizeArray);
    universalClear();
    arr_out(mass,userNumberSizeArray);
    printf("maximal'noe chisl v massive max=%d \n"
           "minimal'noe cislo v massive min=%d \n",arrayMax(mass,userNumberSizeArray),arrayMin(mass,userNumberSizeArray));

    return 0;
}
