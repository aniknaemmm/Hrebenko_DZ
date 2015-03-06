#include <stdio.h>

int myStrlen(const char *string)
{
    int temLen=0;
    while(*string++) temLen++;
    return temLen;
}

int myStrcmp(const char *stringOne,const char *stringTwo)
{
    while(*stringOne&&*stringOne==*stringTwo)
    {
        stringOne++;
        stringTwo++;
    }

    return *stringOne-*stringTwo ;
}

char *myStrcpy(char *destptr,const char *srcptr)
{
    char *newString=destptr;

    while(*srcptr)
    {
        *destptr=*srcptr;
        srcptr++;
        destptr++;
    }
    *destptr=0x0;

    return newString;

}
