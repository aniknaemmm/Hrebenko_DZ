#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Enter the number a:");
    scanf("%d",&a);
    printf("Enter the number b:");
    scanf("%d",&b);
    printf("%d+%d=%d\n",a,b,a+b);
    printf("%d+%d=%d\n",a,b,a-b);
    printf("%d+%d=%d\n",a,b,a*b);
    printf("%d+%d=%d\n",a,b,a/b);
    printf("%d+%d=%d\n",a,b,a%b);

    return 0;
}
