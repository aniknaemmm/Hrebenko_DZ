#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sizennn 300
int main()
{
    char you[sizennn];
    char stack[sizennn];
    int k=-1;
    printf("hello enter you skobki!\n");
    scanf("%s",&you);
    for(int i=0; i<strlen(you); i++)
    {
        if(you[i]=='['||you[i]=='('||you[i]=='{')
        {
            stack[++k]=you[i];
        }
        else if(you[i]=='}'||you[i]==')'||you[i]==']')
        {
            if(k==-1)
            {
                printf("nepravel'no rastavlenni skobki");
                return 0;
            }
           stack[k--];
        }
    }
    printf("skobki stoi9t pravilno");
    return 0;
}