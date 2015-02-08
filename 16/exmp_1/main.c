#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char you[100];
    char stack[100];
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
    printf("skobki stoi9t normal'no");
    return 0;
}