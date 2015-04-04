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
    for(int i=0; i<h; i++)
    {
        printf("\n");
        for(int i2=0; i2<w; i2++)
        {
            printf("#");
        }
    }


}
