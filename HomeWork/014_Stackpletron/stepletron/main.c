#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/compotibility.h"
#include "../../modules/include/stepletron.h"
#define MEMORY 100
#define strok 100

int main()
{
    int arrayTempMemoryProgramm[MEMORY];

    printf("-who stepletron>?\n"
           "-i stepletron\n"
           "-go to work");
    programmEnter(arrayTempMemoryProgramm);

    runProgramm(arrayTempMemoryProgramm);




    return 0;
}
