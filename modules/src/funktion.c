#include <stdio.h>
void function(int userNumb,int osnovanieSystem)
{
    int rez,i=0;
    int fuck[99];

    while(userNumb!=0)
    {
        rez=userNumb%osnovanieSystem;
        fuck[i]=rez;
        userNumb/=osnovanieSystem;
        i++;
    }
    i--;
    while((i+1)!=0)
    {
        if(fuck[i]<9) printf("%d",fuck[i]);
        else printf("%c",55+fuck[i]);
        i--;
    }

}
