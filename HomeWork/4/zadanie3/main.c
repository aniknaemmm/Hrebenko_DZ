#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,numb,max=0,min=0;
    printf("I said : Hello world!\n");
    printf("he said :Hello !\n");
    printf("I said : pls enter n ept:=");
    scanf("%d",&n);
    printf("good .... entter numb[1]=");
    scanf("%d",&numb);
    max=min=numb;
    for(int i=2; i<=n; i++)
    {
        printf("good .... entter numb[%d]=",i);
        scanf("%d",&numb);
        max=(max>numb)?max:numb;
        min=(min<numb)?min:numb;
    }
    printf("max rez=% d\n",max);
    printf("min rez=% d",min);

    return 0;
}
