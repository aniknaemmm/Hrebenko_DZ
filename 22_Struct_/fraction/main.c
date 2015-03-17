#include "fraction.h"

int main(void)
{
    MyNumb firstNumber,nextNumber,result;
    int chois=0;

    printf("hello\n");
    while(!(chois==6)){
        printf("1.enter numb\n2.sum\n3.diff\n4.delen\n5.multiplay\n6.exit\n");
        scanf("%d",&chois);
        system("clear");

        switch (chois) {
        case 1:
            enterNumber(&firstNumber);
            enterNumber(&nextNumber);
            convFractionMixed(&nextNumber);
            convFractionMixed(&firstNumber);
            break;
        case 2:
            result=summ(firstNumber,nextNumber);
            convFractionNoMixed(&result);
            showNumber(result);
            break;
        case 3:
            result=subtraction(firstNumber,nextNumber);
            convFractionNoMixed(&result);
            showNumber(result);
            break;
        case 4:
            result=division(firstNumber,nextNumber);
            convFractionNoMixed(&result);
            showNumber(result);
            break;
        case 5:
            result=multiplication(firstNumber,nextNumber);
            convFractionNoMixed(&result);
            showNumber(result);
            break;
        case 6:
            printf("end\n");
            break;
         default:
            break;
        }

    }


      return 0;
}

