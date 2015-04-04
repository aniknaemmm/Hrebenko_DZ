#include "time.h"

int main(void)
{   Time youTime,tempTime;
    int choi;
    printf("Hello....\npress enter");
    getchar();
    printf("ustanovit vremia ili obnulit'>?(1/2)\n");
    scanf("%d",&choi);
    if(choi==1)
        enterTime(&youTime);
    if(choi==2){
        youTime.hour=0;
        youTime.minut=0;
        youTime.sec=0;
    }
    if(choi!=1&&choi!=2){
        fprintf(stderr,"invalid value");
    exit(1);
    }
    tempTime=youTime;
    while(choi!=4){

        printf("1.adding time\n2.show time \n3.diff time\n4.exit\n");
        scanf("%d",&choi);
        system("clear");
        switch (choi) {
        case 1:
           addTime(&tempTime);
           showTime(tempTime);
            break;
        case 2:
            printf("first time\n");
            showTime(youTime);
            printf("real time\n");
            showTime(tempTime);
            break;
        case 3:
            printf(" diff time %d sec\n",chekTime(youTime,tempTime));

            break;
        case 4:
            printf("end.\n");
            break;

        default:
            fprintf(stderr,"inalid value\n");
            exit(1);
            break;
        }


    }



    return 0;
}

