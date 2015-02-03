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
    int chootnyMass[N];
    int nochotnyMass[N];
    int proverka=0;
    int indexMaxLongDist=-1;
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
        sizeN=sizeN-1;//переход к счёту от нуля;

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
               "2. max sredi chotnix i minimum sredi nechotnix\n"
               "3. maxchotnie meniaem na ix index\n"
               "4. vse chotnie max a ne chotnie min\n"
               "5. posledniu chotni pologit kratnii tvoemu chislu\n");


        printf("choise you task :");
        scanf("%d",&switchUser);
        switch(switchUser)
        {
        case 1 :
            arr_out(mass,sizeN);
            printf("/----------------------------/\n"
                   "/----------new mass----------/\n");
            if(firstPlus(mass,sizeN)!=-1&&lastMinus(mass,sizeN)!=-1)
            {
                transfer(mass,lastMinus(mass,sizeN),firstPlus(mass,sizeN));
                arr_out(mass,sizeN);
            }
            else
                printf("peremeshenie nebilo\n");

            break;
        case 2 :
            arr_out(mass,sizeN);

            if(chotny(mass,sizeN,chootnyMass)!=-1)
                printf("maximal'niy chotniy chlen massiva %d\n",maxNumberArray(chootnyMass,chotny(mass,sizeN,chootnyMass)));
            else
                printf("netu chotnix chisel\n");
            if(nochotny(mass,sizeN,nochotnyMass)!=-1)
                printf("minimal'niy ne cotniy chlen massiva %d\n",minNumberArray(nochotnyMass,nochotny(mass,sizeN,nochotnyMass)));
            else
                printf("netu nechotnix chisel\n");

            break;
        case 3 :
            arr_out(mass,sizeN);
            if(chotny(mass,sizeN,chootnyMass)!=-1)
            {
                maxTransferIndex(mass,sizeN,maxNumberArray(chootnyMass,chotny(mass,sizeN,chootnyMass)));
                printf("/----------------------------/\n"
                       "/----------new mass----------/\n");
                arr_out(mass,sizeN);
            }
            else
                printf("net chotnix chisel");
            break;
        case 4 :
            arr_out(mass,sizeN);
            allTransferMaxadnMin(mass,sizeN,maxNumberArray(chootnyMass,chotny(mass,sizeN,chootnyMass)),minNumberArray(nochotnyMass,nochotny(mass,sizeN,nochotnyMass)));
            printf("/----------------------------/\n"
                   "/----------new mass----------/\n");
            arr_out(mass,sizeN);
            break;
        case 5 :
            arr_out(mass,sizeN);

            printf("enter you naumber :");
            int chotniiElementuMassiva;
            scanf("%d",&chotniiElementuMassiva);
            printf("%d\n",chotny(mass,sizeN,chootnyMass));
            if(chotny(mass,sizeN,chootnyMass)!=-1&&lastPolog(chootnyMass,chotny(mass,sizeN,chootnyMass),chotniiElementuMassiva)!=-1)
            {
                int temp;
                temp=mass[indexMass(mass,sizeN,chootnyMass[lastPolog(chootnyMass,chotny(mass,sizeN,chootnyMass),chotniiElementuMassiva)])];

                mass[indexMass(mass,sizeN,chootnyMass[lastPolog(chootnyMass,chotny(mass,sizeN,chootnyMass),chotniiElementuMassiva)])]=indexMass(mass,sizeN,chootnyMass[lastPolog(chootnyMass,chotny(mass,sizeN,chootnyMass),chotniiElementuMassiva)]);
                mass[sizeN]=temp;
            }

            arr_out(mass,sizeN);
            break;
        case 6 :

                printf("%d",nuli(mass,sizeN,indexMaxLongDist));
                printf("%d",indexMaxLongDist);

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
