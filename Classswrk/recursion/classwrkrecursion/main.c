#include <stdio.h>
#include <stdlib.h>
int fb(int n);
int main()
{
    /*
    int factorifl(int n){
    if(n>0) return n*factorifl(n-1);
    else return 1;
    }
    */

    int n=40;
    printf("%d",fb(n));








    return 0;
}
int fb(int n)//fibonachi
{
    if(n>2)return fb(n-1)+fb(n-2);
    else return 1;



}
