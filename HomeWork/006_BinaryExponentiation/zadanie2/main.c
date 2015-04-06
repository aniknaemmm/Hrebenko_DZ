
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int com=1,n;
    printf("enter numb ");
    scanf("%d",&n);
    for (int i=2; (i*i<=n)&&com; i++)
    {
        if ((n%i)==0)
        {
            com=0;
        }
    }


    printf(com>0?"prostoe":"sostavnoe");

    return 0;
}


