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
 длинный одномернный массив
 int *mtu=NULL;
 mtu=(int *)malloc(m*n*sizeof(int));
 if(mtu==NULL) //ошибка
 mtu[i*n+j]//обращение
    free(mtu);
 mtu=NULL;

//----------------------------------

указаетль на указатель
int **mtu=NULL;
mtu=(int **)malloc(m*sizeof(int*));
if(mtu==NULL) //proverka
for(int i=0;i<m;i++){
    mtr[i]=(int *)malloc(n*sizeof(int));
    if(mtu[i]==NULL)///udalit' vso

}
 mtu[i][j];
 for(int i=0;i<m;i++){
 free(mtu[i]);
 mtu[i]=NULL;
 }
 free(mtu);
 mtu=NULL;
