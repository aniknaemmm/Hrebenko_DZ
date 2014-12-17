#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
double x;
scanf("%lf",&x);
double result=0.0,adding=1.0,eps=1e-4;
int n=1;
while (fabs(adding)>=eps){
    result+=adding;
    adding*=x/n;
    n++;
}

printf("moia exp=%f exp +%f diff=%f",result, exp(x), result-exp(x));

}
