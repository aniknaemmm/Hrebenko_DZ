#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int compNumber,myNumber;
    int myOtvet,bolsheMenshe,vichislenie,mozgi,pravdaLog;
    int kollPop=1;
    printf("Zagadai chislo\n");
    printf("napishi ego ia ne budu ego podsmatrivat' =) Tvoio chislo ");
    scanf("%d",&myNumber);
    compNumber=rand()%98;
    do
    {
        printf("Moio chislo %d\n",compNumber);
        printf("eto twoio chislo?(y=1/n=0)");
        scanf("%d",&myOtvet);
        if(myOtvet==1)
        {
            printf("ia ugadal tvoio chislo za %d popitok\n ",kollPop);
            printf("tvoio chislo %d",compNumber);
        }
        else
        {
            printf("i tak  moio chislo bol'she(1) ili men'she(0)?");
            scanf("%d",&bolsheMenshe);
            if(bolsheMenshe==1)
            {
                printf("aga znachit tvoio chislo men'se\n");
                mozgi=50/kollPop;
                vichislenie=1+rand()%mozgi;
                compNumber-=vichislenie;
            }
            else
            {
                mozgi=50/kollPop;
                printf("aga znachit tvoio chislo bolse\n");
                vichislenie=1+rand()%mozgi;
                compNumber+=vichislenie;
            }

            printf("ia dumaiu.......\n");

        }

        kollPop++;

    }
    while(myOtvet==0);
    printf("\nproverka na log =)\n");

    pravdaLog=myNumber-compNumber;
    if(pravdaLog!=0)
    {

        printf("////\nFALSE\nwow ploxo tak delat ,vrunishka=)");
    }
    else
    {
        printf("////\nTRUE\nbilo veselo!\nspasibo za igru");
    }
}
