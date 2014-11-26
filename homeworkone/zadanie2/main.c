#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Enter the number a:");
    scanf("%d",&a);
    printf("Enter the number b:");
    scanf("%d",&b);
    if((a==7)&&(b==5))
        {
        printf("%d+%d=%d\n",a,b,a+b);
        printf("%d+%d=%d\n",a,b,a-b);
        printf("%d+%d=%d\n",a,b,a*b);
        printf("%d+%d=%d\n",a,b,a/b);
        printf("%d+%d=%d\n",a,b,a%b);
        }
        else
        {
        printf("incorrect data");
        }
    return 0;
}
