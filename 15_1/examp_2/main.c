#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/arr_15_1.h"
#include "../../modules/include/compotibility.h"
#define N 50
int main()
{
    int mass[N];
    int size,userNumberSrch;
    printf("vvedite razmer massiva:");
    scanf("%d",&size);
    universalClear();
    arr_in(mass,size);
    universalClear();
    arr_out(mass,size);
    printf("vvedite chislo dlia poiska :");
    scanf("%d",&userNumberSrch);
    srch(mass,size,userNumberSrch);
    return 0;
}
