#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/arr_15_1.h"
#include "../../modules/include/array_15_b.h"
#include "../../modules/include/compotibility.h"
#include "../../modules/include/liner_rnd.h"

#define N 90
//getch();pause
int main()
{
    int mass[N],sizeN,switchUser;
    int proverka=0;
    do
    {
        universalClear();
        printf("rabota s massivami \"collichesto elementov massiva ot 1 do 90\"\n");
        printf("vvedite coll elementov : ");
        proverka=0;
        do
        {

            if(proverka>0&&proverka<4)
            {
                printf("ERROR \n  chislo ne vxodit v diapozon\n vi vveli %d \n vvedite drugoe chislo :",sizeN);
            }
            else if(proverka==4)
            {
                printf("vi neadekvat!!!!!!");
                exit(1);
            }

            scanf("%d",&sizeN);
            proverka++;
        }
        while(sizeN<1||sizeN>90);
        sizeN-=1;//переход к счёту от нуля;

        universalClear();
        printf("i tak u nas est' massiv kotrii nado zapolnot' kak vi xotite eto zdelat'>?"
               "\nruchnoi vvod - 1\nzapolnit' massiv randomnmi chislami - 2\nviberite 1 ili 2 :");
        proverka=0;
        do
        {

            if(proverka>0&&proverka<4)
            {
                printf("ERROR \n  chislo ne vxodit v diapozon\n vi vveli %d \n vvedite drugoe chislo :",switchUser);
            }
            else if(proverka==4)
            {
                printf("vi neadekvat!!!!!!");
                exit(1);
            }

            scanf("%d",&switchUser);
            proverka++;
        }
        while(switchUser!=1&&switchUser!=2);


        if(switchUser==1)
            arr_in(mass,sizeN);
        else
            randomArray(mass,sizeN);

        universalClear();

        printf("1. per pologit i poslednii otritsatel pomeniat' mestami\n"
               "2. max sredi chotnix i minimum sredi nechotnix\n");

        printf("choise you task :");
        scanf("%d",&switchUser);
        switch(switchUser)
        {
        case 1 :
            arr_out(mass,sizeN);
            printf("/----------------------------/\n"
                   "/----------new mass----------/\n");
            if(firstPlus(mass,sizeN)!=-1&&lastMinus(mass,sizeN)!=-1)
                transfer(mass,lastMinus(mass,sizeN),firstPlus(mass,sizeN));
            else
                printf("peremeshenie nebilo\n");
            arr_out(mass,sizeN);

            break;
        case 2 :
            arr_out(mass,sizeN);

            if(chotny(mass,sizeN)!=-1)
                printf("maximal'niy chotniy chlen massiva %d\n",maxNumberArray(chootnyMass,chotny(mass,sizeN)));
            else
                printf("netu chotnix chisel\n");
            if(nochotny(mass,sizeN)!=-1)
                printf("minimal'niy ne cotniy chlen massiva %d\n",minNumberArray(nochotnyMass,nochotny(mass,sizeN)));
            else
                printf("netu chotnix chisel\n");

            break;
        case 3 :
            arr_out(mass,sizeN);
            if(chotny(mass,sizeN)!=-1){
                maxTransferIndex(mass,sizeN,maxNumberArray(chootnyMass,chotny(mass,sizeN)));
                printf("/----------------------------/\n"
                   "/----------new mass----------/\n");
                arr_out(mass,sizeN);
            }
            else
                printf("net chotnix chisel");

        break;


            default :
            printf("no TASK \n");

        }

        printf("povtorit'>?()(1/2)");
        scanf("%d",&switchUser);

    }
    while(switchUser==1);
    return 0;
}
