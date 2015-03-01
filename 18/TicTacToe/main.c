#include <stdio.h>
#include <stdlib.h>
#include "TTTxo.h"
#include "../../modules/include/ncursesinit.h"


int main()
{
    int ttt[SIZE][SIZE][SIZE]= {0},rez=0;
    initialiseProgram();
    drawTable(ttt);
    while(rez==0)
    {
        playGame(ttt);
        rez=chekWinGame(ttt);

    }
    attron(COLOR_PAIR(blue)|A_BOLD);
    if(rez==1) mvprintw(2,6," Won player O");
    if(rez==2) mvprintw(2,6," Won player X");
    if(rez==-1) mvprintw(2,6,"No player winer");
    refresh();
    attroff(COLOR_PAIR(blue)|A_BOLD);
    getch();
    endwin();
    return 0;
}
