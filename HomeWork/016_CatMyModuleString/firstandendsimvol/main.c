#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/myString.h"
#include "fucStr.h"
#define BUFERSIZE 200
int main()
{

    char str[]="mmilolm mamkam.rama,ramar,ramarar ff rfded fff";
    printf(str);
    printf("\n");
    char bufer[100]= {0};
    showWord(searchWord(str,bufer));
    return 0;
}
