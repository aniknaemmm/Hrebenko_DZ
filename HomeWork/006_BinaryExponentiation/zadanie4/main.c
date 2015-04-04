#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a;
    printf("vvedi stepen ");
    scanf("%d",&n);
    printf("vvedi osnovanie ");
    scanf("%d",&a);
    int res = 1;
    while (n)
    {
        if (n&1)res *= a;
        a *= a;
        n >>= 1;
    }
    printf("result %d",res);
}
