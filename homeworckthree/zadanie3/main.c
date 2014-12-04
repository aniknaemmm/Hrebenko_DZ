#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1;
    for(int i=0;i<17;i++){
    printf("%2d v kube %d\n",n,n*n*n);
    n+=2;
    }

    return 0;
}
