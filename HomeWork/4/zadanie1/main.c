#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0,p=0;i<128;i++,p++){
        if(p==16){
            p=0;
            printf("\n");
            }
        printf(" %-2c-%3d  ",i,i);

        }
    }

