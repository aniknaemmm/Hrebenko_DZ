#include "kakb.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SPACE ".!"
char *searchWord(char *stringOne,char *buferr)
{   int sogl=0,glas=0,level=0;
    char *bufer=buferr;
    char *pts;
    char *str=stringOne;
    pts=strtok(str,SPACE);
    while(pts!=NULL)
    {   level++;
        sogl=0;
        glas=0;
        chekglsn(pts,&sogl,&glas);
        printf("v %d predlogenie %d=sogl %d=glas\n",level,sogl,glas);
        pts=strtok(NULL,SPACE);

    }

    return bufer;
}
void chekglsn(char *stringOne,int *sogl,int *glas){


    char *str=stringOne;
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='o'||str[i]=='i'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='O'||str[i]=='I'||str[i]=='U') *glas+=1;
        else if(str[i]==' '||str[i]==',');
        else *sogl+=1;
    }
}
