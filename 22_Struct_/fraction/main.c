#include "fraction.h"

int main(void)
{
    MyNumb firstNumber,nextNumber,result;
    enterNumber(&firstNumber);
    enterNumber(&nextNumber);
    //result=summ(firstNumber,nextNumber);
    printf("%d-%d\n\n\n",nextNumber.numerator,nextNumber.denumerator);

    convFractionMixed(&nextNumber);
    showNumber(nextNumber);
    convFractionNoMixed(&nextNumber);
    showNumber(nextNumber);


    return 0;
}

