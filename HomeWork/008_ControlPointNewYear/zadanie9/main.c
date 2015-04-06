#include <stdio.h>

int main(void)
{
    int userNumb,i=0;
    int a[90];
    a[0]=0;
    printf("Hello! you numb ");
    scanf("%d",&userNumb);
    while(userNumb!=0){
        if(userNumb>=12) a[i]=userNumb%12;
        else{
            a[i]=userNumb;
            i--;
        }
        userNumb/=12;
        i++;
    }
    printf("10 to 12\n you rezault ");

    for(;i>=0;i--){
        printf("%X",a[i]);
    }


    return 0;
}

