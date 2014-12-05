#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,p;
    int rez=1;
    printf("pls enter x=");
    scanf("\n%d",&x);
    printf("pls enter p=");
    scanf("\n%d",&p);
    for(int i=0;i<p;i++){
                rez=rez*x;
            }
    printf("Otvet xv3=%d",rez);
    return 0;
}
