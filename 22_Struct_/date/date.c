#include "date.h"

void enterDate(Date *data){

    do{
    printf("ente date format dd.mm.gg\n");
    scanf("%d.%d.%d",&data->day,&data->month,&data->year);
    }while(!(chekNormalyEnterDate(*data))&&printf("ivalid value"));

}

bool chekNormalyEnterDate(Date data){
    if(((data.month==aprel)||(data.month==iyun)||(data.month==sentiab)||(data.month==novemb))&&data.day<=30)
        return true;
    if(data.month==feb&&visokYear(data)&&data.day<=29)
        return true;
    if(data.month==feb&&visokYear(data)&&data.day<=28)
        return true;
    if(((data.month==ja)||(data.month==march)||(data.month==mai)||(data.month==iyul)||(data.month==avgust)||(data.month==octab)||(data.month==decemb))&&data.day<=31)
        return true;
    return false;
}

bool visokYear(Date data){
    if(data.year%400==0)
        return true;
    else if(data.year%100==0)
        return false;
    else if(data.year%4==0)
        return true;
    return false;

}

void showDate(Date data){

    printf("%02d.%02d.%04d",data.day,data.month,data.year);
}

void addingDay(Date *date){
    int temp;
    printf("pls enter adding day:");
    scanf("%d",&temp);
    date->day+=temp;
    convDate(date);
}




void convDate(Date *data){
   while((data->day>366)){
        if(visokYear(*data)){
            data->day-=366;
            data->year+=1;
        }else{
            data->day-=365;
            data->year+=1;
        }
  }

   while (!chekNormalyEnterDate(*data)) {
       if(visokYear(*data)&&data->month==feb){
           data->month+=1;
           data->day-=29;
       }
       else if(!visokYear(*data)&&data->month==feb){
           data->month+=1;
           data->day-=28;
       }
       else if((data->month==aprel)||(data->month==iyun)||(data->month==sentiab)||(data->month==novemb)){
           data->month+=1;
           data->day-=30;

       }else{
           data->month+=1;
           data->day-=31;
       }

       if(data->month==13){
           data->month=1;
           data->year+=1;
       }

   }
}

int diffDateDay(Date firsdata,Date nextdata){
    Date temp;
    int diffday=0;
    while((nextdata.month!=firsdata.month)||(nextdata.day!=firsdata.day)||(nextdata.year!=firsdata.year)){

        nextdata.day-=1;
        diffday+=1;
        if(nextdata.day==0){
            if(nextdata.month==march&&visokYear(nextdata))
                    nextdata.day=29;
            else if(nextdata.month==march&&!visokYear(nextdata))
                    nextdata.day=28;
            else if((nextdata.month==aprel)||(nextdata.month==iyun)||(nextdata.month==sentiab)||(nextdata.month==novemb)||(nextdata.month==ja)||(nextdata.month==avgust))
                    nextdata.day=31;
            else nextdata.day=30;
            nextdata.month-=1;
        }


        if(nextdata.month==0){
            nextdata.month=12;
            nextdata.year-=1;
        }
    }
return diffday;


}
/*w*/
