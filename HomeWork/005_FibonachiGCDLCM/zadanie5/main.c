#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h;
    printf("Hello alex!\n");
    printf("pls enter w");
    scanf("%d",&w);
    printf("pls enter h");
    scanf("%d",&h);
    for(int i=1; i<=h; i++)
    {
        if((i==1)||(i==h))
        {
            for(int k=0; k<w; k++)
            {
                printf("#");
            }

        }
        else
        {
            for(int z=1; z<=w; z++)
            {
                if(z==1||z==w)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}
