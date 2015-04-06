#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numberOne,numberTwo,rez=0,contin;
    char deistvie;
    do{
        system("cls");
        printf("please enter the formula in format \"number one next simvol action and next simvol number two\".\n");
        scanf("%d%c%d",&numberOne,&deistvie,&numberTwo);
        switch(deistvie){
             case '+':rez=numberOne+numberTwo;
             break;
             case '-':  rez=numberOne-numberTwo;
             break;
             case '*':  rez=numberOne*numberTwo;
             break;
             case '/':  rez=numberOne/numberTwo;
             break;
             default : printf("unknow error \a");
             return 0;
         }
         system("cls");
         printf("%d%c%d=%d\n",numberOne,deistvie,numberTwo,rez);
         printf("again>?(1/0)");
         scanf("%d",&contin);
    }while(contin==1);
printf("Good By");

    return 0;
}

