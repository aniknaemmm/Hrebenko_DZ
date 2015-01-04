#include <stdio.h>

int main(void)
{

    int startMonySasha=100000,procentSasha=0,rezTmonth=0;
    int monySasha=100000,monyVasia=100000;
    int month=3;
    printf("_______________________________________________\n");
    printf("|  month    ||      sasha 6%% ||     vasia  4%% | \n");
    do{
        procentSasha=((double)startMonySasha/100)*6;
        monySasha+=procentSasha;
        monyVasia+=(monyVasia/100)*4;
        printf("| %3d month || %4d.%02d dolars|| %4d.%02d dolars|\n",month,monySasha/100,monySasha%100,monyVasia/100,monyVasia%100);
        month+=3;
        if(monySasha<monyVasia) rezTmonth++;
    }while((monySasha>monyVasia)||(rezTmonth<3));
printf("-----------------------------------------------\n");






    return 0;
}

