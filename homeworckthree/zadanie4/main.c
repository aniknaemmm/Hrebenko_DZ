#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numb,nn;
    int sum=1,i=0;
    printf("Hello pls entr kolichestvo cifr ");
    scanf("\n%d",&numb);
    while(numb--){
        i++;
        printf("pls entr numb%d =",i);
        scanf("%d",&nn);
        sum=sum*nn;
        }
    printf("Otvet =%d",sum);
    return 0;
}
