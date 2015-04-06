#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,p,rez=1;
    printf("Hello world!\n");
    printf("enter x\n");
    scanf("%d",&x);
    printf("enter p\n");
    scanf("%d",&p);
    printf("well done you entered x:=%d and p:=%d\n",x,p);
    if(p<0)
    {
        p*=-1;
        for(int i=0; i<p; i++)
        {
            rez*=x;
        }
        if(rez==0)
        {
            printf(" wonderful rez=%d",rez);
        }
        else
        {
            printf(" oh my good rez=%.3f",1.0/rez);
        }
    }
    else
    {
        for(int i=0; i<p; i++)
        {
            rez*=x;
        }
        printf("Rez-Rez-zzZzz rez=%d",rez);
    }



    return 0;
}
