#include <stdio.h>
#include <stdlib.h>
#include "TTTxo.h"
#include "../../modules/include/compotibility.h"
#define SIZE 4

int main()
{
    printf("Hello world!TTTxo\n");
    int who=0,rez=0;
    int ttt[SIZE][SIZE][SIZE]= {{{0}}};
        tttOxShow(ttt);
    for(int i=0; (i<SIZE*SIZE*SIZE)&&(rez==0); i++,who++)
    {
        playTTTox(ttt,who);
        universalClear();
        rez=vektorTTTox(ttt);
        tttOxShow(ttt);
        if(rez==2) printf("winer 2");
        if(rez==1) printf("winer 1");
    }



    return 0;
}
