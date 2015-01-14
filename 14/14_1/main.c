#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/myfans.h"
int main()
{
    int a,b;
    printf("pls enter two numbers:\n");
    scanf("%d%d",&a,&b);
    printf("gcd(%d,%d) = %d\n",a,b,gcd(a,b));
    printf("lmc(%d,%d) = %d",a,b,lmc(a,b));
    return 0;
}
