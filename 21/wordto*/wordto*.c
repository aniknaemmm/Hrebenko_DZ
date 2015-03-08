#define SPACE " ,.!?\n"
#include <string.h>
#include <stdio.h>
#include "wordto*.h"
#include <math.h>
char *searchProstSlov(const char *stringOne,char *bufer)
{
    char str[1024]="",*pts;;
    strcat(str," ");
    strcpy(str,stringOne);
    pts=strtok(str,SPACE);
    while(pts!=NULL)
    {
        if(chekProstoe(pts))
        {
            strcat(bufer," ");
            strcat(bufer,pts);
            strcat(bufer,"!");
        }
        pts=strtok(NULL,SPACE);
    }
    return bufer;
}


int chekProstoe(char *stringone)
{
    if(strlen(stringone)==1) return 0;
    for(int i=2; i<=sqrt(strlen(stringone)); i++)
        if(strlen(stringone)%i==0)
            return 0;
    return 1;
}

void zamenaSlov(char *stringOne,char *bufer)
{
    char *temp;
    char *str=bufer;
    char *pts;
    pts=strtok(str,"!");
    while(pts!=NULL)
    {
        temp=strstr(stringOne,pts);
        if(temp!=NULL&&((temp[strlen(pts)]==' ')||(temp[strlen(pts)]=='.')||(temp[strlen(pts)]=='!')||(temp[strlen(pts)]==',')))
        {
            for(int i=1; i<strlen(pts); i++)
            {
                temp[i]='*';

            }
        }
        pts=strtok(NULL,"!");
       }
}
