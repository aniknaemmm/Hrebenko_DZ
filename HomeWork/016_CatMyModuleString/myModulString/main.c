#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../modules/include/myString.h"
int main()
{
    printf("Hello world!\n");
    char temp0[10]="mamka";
    char temp1[6];
    char temp2[20];
    char temp3[30]="wtfkaka";
    myStrcpy(temp1,temp0);
    strcpy(temp2,temp0);
    fprintf(stdout,"%s   //temp0 string\n%s  //copy std lib function\n%s //copy my function",temp0,temp1,temp2);
    fprintf(stdout,"use nex function");
    printf("\n%d result my function   %d result std lib function\n",myStrlen(temp0),strlen(temp1));
    fprintf(stdout,"printf string temp3[]=%s\n",temp3);
    fprintf(stdout,"\ncopy string temp3 to temp1\n%s",myStrcpy(temp0,temp3));

  return 0;
}
