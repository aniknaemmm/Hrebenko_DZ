#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{   double eps=1e-4;
    double sum=1;
    for(double x=-2;x<=2.1;x+=0.1){
         double n=1;
         double res=0;sum=x;
         while (fabs(sum)>=eps) {
                   res+=sum;
                   sum*=(-1)*x*x/(2*n)/(2*n+1);
                   n++;
        }
    printf("x=% .1f moi sin(n)=% .4f function sin(n)=% .4f diff=%.5f\n",x,res,sin(x),fabs(res-sin(x)));
    }
return 0;
}

