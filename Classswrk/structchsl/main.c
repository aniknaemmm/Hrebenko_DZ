#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Fraction_
{
    int num,denom;
} Fraction;

Fraction sum(Fraction a,Fraction b)
{
    assert(a.denom>0);
    assert(b.demon>0);
    Fraction result;
    result.num=a.num*b.denom+b.num*a.denom;
    result.denom=a.denom*b.denom;
    int div=gcd(result.num,result.denom);
    result.num/=div;
    result.denom/=div;
    return  result;
}




int main()
{
    printf("Hello world!\n");
    return 0;
}

сто и грязное дерево
/--------------------






