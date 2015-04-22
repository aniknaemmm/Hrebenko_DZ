#include <stdio.h>
#include <math.h>
#include <unistd.h>
int main(void)
{
    short int  buf[64];

    for(int i = 0; i < 44100*5/32; i++)
    {
        for(int k = 0; k < 64; k+=2)
        {
            buf[k] = 20000 * sin((i*32+k)*2.0*3.1415926536*440.0/44100.0);
            buf[k+1] = buf[k];
        }

        write(1, buf, 64 * sizeof(short int));
    }

    return 0;
}

