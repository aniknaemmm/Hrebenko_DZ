#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/arr_15_1.h"
#include "../../modules/include/compotibility.h"
#include "../../modules/include/liner_rnd.h"
#include "raz.h"
#define N 50

int main()
{
    int mass[N];
    int sizeN,switchUser;
    printf("Hello world!\nenter size massiv:");
    do{
            scanf("%d",&sizeN);
    }while(sizeN<=0||sizeN>50);
    printf("vvesti massiv vruchnuiy(1) ili random(2) :");
    do{
            scanf("%d",&switchUser);
    }while(switchUser!=1&&switchUser!=2);

    if(switchUser==1)
        arr_in(mass,sizeN);
    else {
        for(int i=0;i<sizeN;i++){
            mass[i]=rand()%101+1;
        }
    }
    universalClear();

    arr_out(mass,sizeN);
    //universalSleep(10);



    if(posledniMinus(mass,sizeN)==-1) printf("net otritcatel'nix chisel\n");
    else printf ("poslednee otritcatel'noe chiso %d s nomerom v massive %d\n",mass[posledniMinus(mass,sizeN)],posledniMinus(mass,sizeN));

    if(posledniMinus(mass,sizeN)==-1) printf("net pologitel'nix chisel\n");
    else printf ("pervoe pologitelnoe chiso %d s nomerom v massive %d\n",mass[perviiPlus(mass,sizeN)],perviiPlus(mass,sizeN));

    return 0;
}
