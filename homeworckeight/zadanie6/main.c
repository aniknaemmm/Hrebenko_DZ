#include <stdio.h>
int main(void)
{
    int ivanVasilevichTime=0,sumFlies,exorcismSpeed,fatiqueTime,flyReturnSpeed;
    printf("Hello sumFlies = ");
    scanf("%d",&sumFlies);
    printf("pls enter exorcismSpeed = ");
    scanf("%d",&exorcismSpeed);
    printf("pls enter fatiqueTime = ");
    scanf("%d",&fatiqueTime);
    printf("pls enter flyReturnSpeed = ");
    scanf("%d",&flyReturnSpeed);

    while(sumFlies>0&&(exorcismSpeed>flyReturnSpeed)){
        if(ivanVasilevichTime==fatiqueTime) exorcismSpeed-=exorcismSpeed*20.0/100;
        sumFlies-=exorcismSpeed;
        sumFlies+=flyReturnSpeed;
        ivanVasilevichTime++;
         }
    if(exorcismSpeed<=flyReturnSpeed) printf("unreal ecsorcism files");
    else  printf("ivan Vasilevich exorcism files through %d minuts",ivanVasilevichTime);
    return 0;
}

