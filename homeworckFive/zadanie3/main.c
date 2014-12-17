#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fibaone=1,fibatwo=0;
    int a,b,c;
    for(int i=1;i<=40;i++){
    a=fibaone+fibatwo;
    fibaone=fibatwo;
    fibatwo=a;
    printf("  numb[%2d] fibonach %10d  numb[%2d]/numb[%2d]=%.3f  numb[%2d]/numb[%2d]=%.3f\n",i,fibatwo,i,i+1,fibatwo*1.0/(fibaone+fibatwo),i,i-1,fibatwo*1.0/fibaone);
    }
    return 0;
}
