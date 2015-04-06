#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#include <time.h>
#include "../../modules/include/array_sort.h"
int main()
{   srand(time(NULL));
    int arraY[SIZE],sizeN=SIZE;
    printf("Hello world!\n");
    randInArray(arraY,sizeN);
    showArrayint(arraY,sizeN);
    bubbleSort(arraY,sizeN);
    showArrayint(arraY,sizeN);
    return 0;
}
