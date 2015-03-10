#include "myCat.h"

void enterNumber(MyNumb *data){

    printf("enter integer_numerator_denumerator\n");
    scanf("%d%d%d",&data->integer,&data->numerator,&data->denumerator);
}

void showNumber(MyNumb number){

    printf("%d %d/%d",number.integer,number.numerator,number.denumerator);

}

MyNumb summ(MyNumb first,MyNumb next){
    MyNumb result;
    result.integer=first.integer+next.integer;
    result.numerator=first.numerator+next.numerator;
    result.denumerator=first.denumerator+next.denumerator;
    return result;
}
