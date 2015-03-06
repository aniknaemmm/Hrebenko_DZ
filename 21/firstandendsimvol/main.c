#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/myString.h"
#include "fucStr.h"
int main()
{
    printf("Hello world!\n");
    char str[]="mmilolm mamkam.rama,ramar,ramarar ff rfded fff";
    char bufer[100]={0};
    showWord(searchWord(str,bufer));
    return 0;
}
