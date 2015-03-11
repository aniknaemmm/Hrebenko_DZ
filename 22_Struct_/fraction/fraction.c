#include "fraction.h"

void enterNumber(MyNumb *data){
    do{
    printf("enter integer_numerator_denumerator\n");
    scanf("%d%d%d",&data->integer,&data->numerator,&data->denumerator);
    }
    while(data->denumerator==0&&printf("err denum =0\n"));

}

void showNumber(MyNumb number){

    printf("%d-%d/%d\n",number.integer,number.numerator,number.denumerator);

}


void convFractionMixed(MyNumb *data){
    int temp=0;
    temp=data->integer*data->denumerator;
    data->numerator+=temp;
    data->integer=0;
}

void convFractionNoMixed(MyNumb *data){
    int temp=0;
    if(abs(data->numerator)>data->denumerator){
    temp=data->numerator/data->denumerator;
    data->integer+=temp;
    data->numerator-=temp*data->denumerator;
    }
}


MyNumb summ(MyNumb first,MyNumb next){
    MyNumb result;

    result.integer=first.integer+next.integer;
    result.numerator=first.numerator+next.numerator;
    result.denumerator=first.denumerator+next.denumerator;

    return result;
}
