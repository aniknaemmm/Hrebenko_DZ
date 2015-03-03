#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void zuzu(int *a){
*a*=3;


}


//указатель на функцию
тип (*имя_указателя)(тип1.тип2.тип3...);
int (*fptr)(int,int);
//-------------------------------------
fptr=gcd;
c=(*fptr)(12,16);
    fprt=lcm;
d=(*fptr)(12,16);
применение
1 функции высокого порядка
2 таблицы функций

ФУНКЦИИ ВЫСОКОГО ПОРЯДКА
возрощ функцию.

void bubleSort(int *a,int n,boll(*less)(int,int)){

for(int i=1;i<n;++i){
    for(int j=0;j<n-i;j++){
        if(less(a[j+1],[j]))
            swap(&a[j],&a[j+1]);
    }
}




}


