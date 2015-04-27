#include <stdio.h>

int main(void)
{
    FILE *file;
    file = fopen("message.bin", "rb");
    int buf[256] = {0};

    while(!feof(file))
    {
        buf[fgetc(file)]++;
    }
    int nzero;
    for(int i = 0; i < 256; i++)
    {
        if(buf[i]>0)
            nzero++;
        printf("%d - %d\n", i, buf[i]);
    }
    printf("nzero %d",nzero);



    printf("Hello World!\n");
    return 0;
}

