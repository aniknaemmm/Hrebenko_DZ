#include "TTT.h"
#include <stdlib.h>
#include "../../modules/include/ncursesinit.h"
int main()
{
    int mass[20][20]= {{{0}}},chek_result=0;
    initialiseProgram();

    drawTable(mass);
    while(chek_result==0)
    {
        playGame(mass);
        chek_result=chekWinGame(mass);
    }

    if(chek_result==1)
    {
        attron(COLOR_PAIR(blue)|A_BLINK);
        mvprintw(SIZE/2,SIZE+SIZE/2,"Winer O");
        attroff(COLOR_PAIR(blue)|A_BLINK);
    }
    else if(chek_result==2)
    {
        attron(COLOR_PAIR(blue)|A_BLINK);
        mvprintw(SIZE/2,SIZE+SIZE/2,"Winer X");
        attroff(COLOR_PAIR(blue)|A_BLINK);
    }
    else
    {
        attron(COLOR_PAIR(red)|A_BLINK);
        mvprintw(SIZE/2,SIZE+SIZE/2,"no winer");
        attroff(COLOR_PAIR(red)|A_BLINK);

    }
    refresh();
    getch();
    endwin();
    return 0;
}



