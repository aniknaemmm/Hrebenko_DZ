#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/compotibility.h"
#include "../../modules/include/Home_15_sqr.h"
int main()
{   int sizez;
    printf("Hello world!\nenter you size sqr:");
    scanf("%d",&sizez);
    sqr(sizez);
    universalClear();
    printf("#");
    return 0;
}
