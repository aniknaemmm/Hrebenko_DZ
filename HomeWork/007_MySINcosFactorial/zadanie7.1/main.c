#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){


    double eps=1e-4,result,sum;
    for(double x=-2;x<=2;x+=0.1){
        result=0;
        int n=1;
        sum=1;
         while(fabs(sum)>=eps){
             result+=sum;
             sum*=x/n;
             n++;


         }

printf("x=% .1f moia exp(n)=%.4f function exp(n)=%.4f diff=% .5f \n",x,result,exp(x),result-exp(x));


}
}
