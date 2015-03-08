#include <stdio.h>
#include <stdlib.h>
#include "wordto*.h"
int main()
{
    char str[10000];
    char bufer[100]= {0};
    FILE *file;
    file=fopen("../txet.txt","r");
    if(file != NULL)
    {
        fgets(str,sizeof(str),file);

    }
    else
    {
        fprintf(stderr,"err");
        exit(1);
    }

    printf(str);
    printf("\n");
    zamenaSlov(str,searchProstSlov(str,bufer));

    printf(str);

    fclose(file);
    return 0;
}

