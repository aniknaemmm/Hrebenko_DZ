#include "time.h"

void enterTime(Time *data){

    printf("--.--.--\n");
    scanf("%d.%d.%d",&data->hour,&data->minut,&data->sec);
    wtfTime(data);
}
void showTime(Time data){

    printf("hours|minut|sec\n"
           " %03d| %03d|%03d \n",data.hour,data.minut,data.sec);
}


void  wtfTime(Time *data){

    while(data->sec>=60){
        data->minut+=1;
        data->sec-=60;
    }

    while(data->minut>=60){
        data->hour+=1;
        data->minut-=60;
    }

}

void addTime(Time *data){
    int addTime;
    printf("pls enter adding time (sec):");
    scanf("%d",&addTime);
    data->sec+=addTime;
    wtfTime(data);


}

int chekTime(Time firstTime,Time realTime){
    Time temp;
    int result=0;
    temp.hour=realTime.hour-firstTime.hour;
    temp.minut=realTime.minut-firstTime.minut;
    temp.sec=realTime.sec-firstTime.sec;
    result=temp.hour*60*60+temp.minut*60+temp.sec;
    return result;
}
