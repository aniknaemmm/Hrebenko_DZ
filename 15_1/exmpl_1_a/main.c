#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/liner_rnd.h"

int main()
{
    for(int i=0; i<10; i++)
    {
        printf("Hello world!%d\n",rand()%101);
    }
    return 0;
}
