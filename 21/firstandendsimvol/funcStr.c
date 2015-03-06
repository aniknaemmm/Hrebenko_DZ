#include "../../modules/include/myString.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SPACE " .,!\n\t\r~"
char *searchWord(char *stringOne,char *buferr)
{
    char *bufer=buferr;
    char *pts;
    char *str=stringOne;
    pts=strtok(str,SPACE);
    while(pts!=NULL)
    {
        if((*pts==*(pts+strlen(pts)-1)))
        {
            strcat(bufer,pts);
            strcat(bufer," ");
        }
        pts=strtok(NULL,SPACE);
    }

    return bufer;
}
void showWord(char *stringOne){

    char bufer[100]={0};
    char *pts;
    char *str=stringOne;

    pts=strtok(str,SPACE);

    while(pts!=0)
    {
        if(strstr(bufer,pts)==NULL)
        {
            strcat(bufer,pts);
            strcat(bufer," ");
        }
        pts=strtok(NULL,SPACE);

    }
    if(*bufer!=0)printf(bufer);
    else printf("no symbols");
}
