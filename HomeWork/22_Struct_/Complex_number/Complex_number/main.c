#include "complex.h"



int main(void)
{
   Complex firstNumb, nextNumb, result;
   int choTemp;
   printf("Hello .....\npress enter");
   getchar();
   printf("1.sum\n2.nosum\n3.multip\n4.delenie\n");
   scanf("%d",&choTemp);
   system("clear");
   switch (choTemp) {
   case 1:
       printf("pls enter first numb\n");
       enterComplexNumb(&firstNumb);
       printf("pls enter next numb\n");
       enterComplexNumb(&nextNumb);
       result=summComplexNumb(firstNumb,nextNumb);
       showComplexNumb(result);
       break;
   case 2:
       printf("pls enter first numb\n");
       enterComplexNumb(&firstNumb);
       printf("pls enter next numb\n");
       enterComplexNumb(&nextNumb);
       result=nosummComplexNumb(firstNumb,nextNumb);
       showComplexNumb(result);
       break;
   case 3:
       printf("pls enter first numb\n");
       enterComplexNumb(&firstNumb);
       printf("pls enter next numb\n");
       enterComplexNumb(&nextNumb);
       result=multComplexNumb(firstNumb,nextNumb);
       showComplexNumb(result);
       break;
   case 4:
       printf("pls enter first numb\n");
       enterComplexNumb(&firstNumb);
       printf("pls enter next numb\n");
       enterComplexNumb(&nextNumb);
       result=desmComplex(firstNumb,nextNumb);
       showComplexNumb(result);
       break;


   default:
       fprintf(stderr,"unknow value\n");
       exit(1);
       break;
   }

    return 0;
}

