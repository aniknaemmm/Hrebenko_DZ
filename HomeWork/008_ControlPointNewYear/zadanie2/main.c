#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n,oneN,twoN,colNumb=0;
    int res=0;
    int twoNn=1;
    printf("hello pls enter you numb n=");
    scanf("%d",&n);
    system("cls");
    oneN=n;
    while(oneN){
        colNumb++;
        oneN/=10;
    }
     oneN=n;
     twoN=n;
     int kn=pow(10,colNumb)/10;
     for(int p=1;(p<=colNumb/2)&&(twoNn==1);p++,kn/=10,oneN/=10){
        res=twoN/kn-oneN%10;
        if(res%10!=0) twoNn=0;
        }

        if(twoNn==0) {
           printf(" you number %d ne polindromom\n",n);
        }else{
           printf(" you number %d polindromom\n",n);
        }
    return 0;
}

