#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/compotibility.h"
#include "Tictaxtoe20x20.h"
#define SIZE 20
int main()
{
    printf("Hello world!\n");
    int ticTacMazafak_array[SIZE][SIZE]= {{0}},who=0,rez=0;


    for(int p=0; p<SIZE*SIZE&&rez==0; p++,who++)
    {
        playTTTox(ticTacMazafak_array,who);
        tttOxShow(ticTacMazafak_array);
        rez=chekWinGame(ticTacMazafak_array);
        if(rez==2)return printf("winer 2");
        if(rez==1)return printf("winer 1");
    }

    return 0;
}
