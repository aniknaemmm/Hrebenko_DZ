#include <stdio.h>
void arr_in(int mass[],int size)
{
    for(int i=0; i<=size; i++)
    {
        printf("vvedite %d element massiva a[%d]=",i+1,i);
        scanf("%d",&mass[i]);
    }
}


void arr_out(int mass[],int size)
{
    for(int i=0; i<=size; i++)
    {
        printf("a[%2d]=% d\n",i,mass[i]);
    }
}


void srch(int mass[],int size,int userNumberSrch)
{
    int index=-1;
    for(int i=0; i<=size&&index==-1; i++)
    {
        if(mass[i]==userNumberSrch) index=i;

    }
    printf("index tvoego chisla %d",index);

}
