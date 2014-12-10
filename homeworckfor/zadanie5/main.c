#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,rez,rez1=1,rez2=1;
    printf("Hello world!\n");
    scanf("%d",&n);

    for(int i=1 ; i<=n; i++)
    {
        if(i==1)
        {
            printf("1 ");
        }
        else if(i==2)
        {
            printf("1 ");
        }
        else
        {
            rez=rez1+rez2;
            printf("%d ",rez);

            rez2=rez1;
            rez1=rez;
        }

    }
    return 0;
}
