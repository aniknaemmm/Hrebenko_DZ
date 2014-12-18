#include <stdio.h>
#include <stdlib.h>

int main()
{   int userNubmber,summ=0,i=0;

    printf("Hello\n");
    printf("Vvedi chislo \n");
    scanf("%d",&userNubmber);
    while(userNubmber){
        i=userNubmber%10;
        summ+=i;
        userNubmber/=10;

    }
printf("you result sum=%d",summ);


    return 0;
}
