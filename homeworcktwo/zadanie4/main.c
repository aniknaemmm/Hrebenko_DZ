#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    int b=1;
    int c=10;
    int d=10;
    printf("%*c%d\n%*c%d\n%*c%d\n%*c%d\n",1,' ',a,2,' ',b,3,' ',c,4,' ',d);
    return 0;
}
