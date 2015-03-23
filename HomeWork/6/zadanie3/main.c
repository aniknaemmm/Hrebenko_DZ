#include <stdio.h>
#include <stdlib.h>

int main()
{

    int number,start,x=0;
    int p=1,strokka=0;
int i;
    printf("vvedi ne chotnoe chislo ");
    scanf("%d",&number);
    start=(number+1)/2;

    for(i=0; i<=start; i++)
    {
        for(; x<start; x++)
        {
            printf(" ");

        }

        for(p=0; p<=strokka*2; p++)
        {
            if(p==0||p==strokka*2)
            {
                printf("#");
            }
            else printf("*");
        }
        strokka++;
        x=strokka;
        printf("\n");

    }
    strokka--;
    x--;

    for(i=0; i<=start; i++)
    {
        if(i==0)
        {
            strokka--;
            x=strokka;
        }
        else
        {
            for(; x<start; x++)
            {
                printf(" ");

            }

            for(p=0; p<=strokka*2; p++)
            {
                if(p==0||p==strokka*2)
                {
                    printf("#");
                }
                else printf("*");
            }
            strokka--;
            x=strokka;
            printf("\n");

        }
    }




}
