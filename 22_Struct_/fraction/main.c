#include "fraction.h"

int main(void)
{
    MyNumb firstNumber,nextNumber,result;
    enterNumber(&firstNumber);
    enterNumber(&nextNumber);
    convFractionMixed(&nextNumber);
    convFractionMixed(&firstNumber);
    printf("sum\n");
    result=summ(firstNumber,nextNumber);
    convFractionNoMixed(&result);
    showNumber(result);
    printf("division\n");
    result=division(firstNumber,nextNumber);
    convFractionNoMixed(&result);
    showNumber(result);
    printf("substraction\n");
    result=subtraction(firstNumber,nextNumber);
    convFractionNoMixed(&result);
    showNumber(result);
    printf("multiplication\n");
    result=multiplication(firstNumber,nextNumber);
    convFractionNoMixed(&result);
    showNumber(result);

    return 0;
}

