#include "myCat.h"

int main(void)
{
    MyNumb firstNumber,nextNumber,result;
    enterNumber(&nextNumber);
    enterNumber(&firstNumber);
    result=summ(firstNumber,nextNumber);
    showNumber(result);



    return 0;
}

