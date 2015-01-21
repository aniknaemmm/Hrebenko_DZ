#include <stdio.h>
#include <stdlib.h>
void hanoi(int d, char from,char to,char helper);
int main()
{
    printf("Hello world!\n");
    hanoi(1,'a','b','c');
    return 0;
}

void hanoi(int d, char from,char to,char helper)
{
    if(d>0)//togda nam nenado else esli d>0 && nado elsi esli d>1
    {
        hanoi(d-1, from,helper,to);
        printf("%c -> %c\n",from,to);
        hanoi(d-1, helper,to,from);
    }
    else printf("%c -> %c\n",from,to);

}


/*spiral



*/
