#include <stdlib.h>
int fibonachi(int n)
{

    int *memory;
    meory=(int *)malloc((n+1)*sizeof(int));
    for(int i=0; i<=n; i++)
    {
        memory[i]=-1;
    }
    memory[0]=0;
    memory[1]=1;
    int result=fibImpl(memory,n);
    free(memory);
    return result;
}
int fibImpl(i nt *memory,int n)
{

    if(memory[n]<0)
        memory[n]=fibImpl(memory,n-1)+fibImpl(memory,n-2);
    return memory[n];

}
