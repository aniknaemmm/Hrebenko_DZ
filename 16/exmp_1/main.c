#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sizennn 300
int main()
{
    char *you=NULL;
    char *stack=NULL;
    you=(char *)malloc(sizennn*sizeof(char));
    stack=(char *)malloc(sizennn*sizeof(char));
    if(you==NULL||stack==NULL)
    {
        fprintf(stderr,"memory is full");
        exit(1);
    }
    int ziz=0;
    int k=-1;
    printf("hello enter you skobki!\n");

    do
    {
        you[ziz]=getchar();
    }
    while(you[ziz++]=='\n');

    for(int i=0; i<ziz; i++)
    {
        if(you[i]=='['||you[i]=='('||you[i]=='{')
        {
            stack[++k]=you[i];
        }
        else if((you[i]=='}'&&stack[k]!='{')||(you[i]==']'&&stack[k]!='[')||(you[i]==')'&&stack[k]!='(')||(i==ziz-1&&k!=-1))
        {
            printf("eror");
            return 0;
        }
        else
        {
            k--;
        }

    }
    printf("correctly brackets ");
    free(you);
    free(stack);
    return 0;
}


