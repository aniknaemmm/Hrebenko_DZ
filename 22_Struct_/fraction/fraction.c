#include "fraction.h"

int gcd(int first,int next){
    int temp;
      while (next) {
         temp  = first % next;
         first = next;
         next  = temp;
      }
      return abs(first);
}

void enterNumber(MyNumb *data){
    do{
    printf("enter integer_numerator_denumerator\n");
    scanf("%d%d%d",&data->integer,&data->numerator,&data->denumerator);
    }
    while(data->denumerator==0&&printf("err denum = 0\n"));

}

void showNumber(MyNumb number){

    if(number.numerator==0)
        printf("%d\n",number.integer);
    if(number.integer==0&&number.numerator!=0)
        printf("%d/%d\n",number.numerator,number.denumerator);
    if(number.integer!=0&&number.numerator!=0)
        printf("%d-%d/%d\n",number.integer,number.numerator,number.denumerator);
}


void convFractionMixed(MyNumb *data){
    int temp=0;
    temp=data->integer*data->denumerator;
    data->numerator+=abs(temp);
    if(temp<0)
        data->numerator*=-1;
    data->integer=0;
}

void convFractionNoMixed(MyNumb *data){
    int temp=0;
    if(abs(data->numerator)>abs((data->denumerator))){
        temp=data->numerator/data->denumerator;
        data->integer+=temp;
        data->numerator-=temp*data->denumerator;
    }
    if(data->denumerator==data->numerator){
         data->numerator=0;
         data->integer+=1;
    }
    if(data->numerator!=0&&(temp=gcd(data->numerator,data->denumerator))!=1){
        data->numerator/=temp;
        data->denumerator/=temp;
    }
}


MyNumb summ(MyNumb first,MyNumb next){
    MyNumb result;
    if(first.denumerator==next.denumerator){
    result.numerator=first.numerator+next.numerator;
    result.denumerator=first.denumerator;
    }
    else{
    result.numerator=first.numerator*next.denumerator+next.numerator*first.denumerator;
    result.denumerator=next.denumerator*first.denumerator;
    }
    result.integer=0;
    return result;
}

MyNumb multiplication(MyNumb first,MyNumb next){
    MyNumb result;
    result.numerator=first.numerator*next.numerator;
    result.denumerator=first.denumerator*next.denumerator;
    result.integer=0;
    return result;
}

MyNumb division(MyNumb first,MyNumb next){
    MyNumb result;
    result.denumerator=first.denumerator*next.numerator;
    result.numerator=first.numerator*next.denumerator;
    result.integer=0;
    return result;
}

MyNumb subtraction(MyNumb first,MyNumb next){
    MyNumb result;
    if(first.denumerator==next.denumerator){
        result.numerator=first.numerator-next.numerator;
        result.denumerator=first.denumerator;
       }
    else{
        result.numerator=first.numerator*next.denumerator+next.numerator*first.denumerator;
        result.denumerator=next.denumerator*first.denumerator;
    }
    result.integer=0;
    return result;
}
