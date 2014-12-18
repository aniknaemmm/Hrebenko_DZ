#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    printf("pls enter =");
    scanf("%d",&n);
    printf("\n%d=",n);
    int i=2;
    while (i*i<=n)
        if ((n%i)==0)
        {
            printf("%d*",i);
            n = n/i;
        }
        else
            i = i+1;

    printf("%ld",n);

    return 0;
}
