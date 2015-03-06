#include <stdio.h>
#include <stdlib.h>
#include "kakb.h"
int main()
{

    char str[]="Uhls started working on an early draft of the adapted screenplay. Which excluded a voice-over because the industry perceived at the time that the technique was \"hackneyed and trite\"";
    char bufer[100]={0};
    printf(str);
    printf("\npoexali!\n");
    searchWord(str,bufer);
    return 0;
}
