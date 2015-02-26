/*#include <stdio.h>
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
}*/

#define _XOPEN_SOURSE_EXTENDED
#define _POSIX_C_SOURSE 199309L

#include <sys/ioctl.h> //esli my zahotim izmenit' razmer konsoli (pishetsya vmeste s <signal.h>)
#include <signal.h>    //poluchaet signal ot OS o tom chto nuzhno pomenyat' razmer consoli
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>    //kodirovka?
static char unusedCell[4] = "\342\227\206";
enum Colors{normal, green, red,yellow}; // perechislenie cvetov
void treatSigWinch(int signo);

void initialiseProgram()
{
    setlocale(LC_ALL, "");
    initscr();   //zastavlyaem ncurses rabotat'
    signal (SIGWINCH, treatSigWinch); //vtoroy parametr nazyvaem kak hotim, perviy obyazatel'no tak
    if(has_colors()==FALSE)
    {
        endwin();
        fprintf(stderr, "no colors/n");
        exit(1);
    }
    cbreak();
    noecho(); //pryachem to chto nabiraem
    curs_set(0); //pryachem kursor
    start_color();
    //init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(normal, COLOR_WHITE, COLOR_BLACK);
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
    init_pair(yellow, COLOR_YELLOW, COLOR_BLACK);
}

void treatSigWinch(int signo)
{
    struct winsize size;
    ioctl(1, TIOCGWINSZ, (char *) &size); //menyaem razmer konsoli
    resizeterm(size.ws_row, size.ws_col);
}


int main()
{   int m=4,n=4;
    initialiseProgram();

    attron(A_REVERSE);
    attron(COLOR_PAIR(yellow)); //vklyuchaem cvet
    printw("Hello world!");
    attroff(COLOR_PAIR(yellow));

    attroff(A_REVERSE);
    refresh(); //ne zabyvat'!!!
    getch(); //ozhidaet lyubogo vvoda klavish
    attron(COLOR_PAIR(green));
     attron(A_REVERSE);
    attron(A_BLINK|A_BOLD);
    flash();
    move(5, 3);
   printw("%s", unusedCell);
    attroff(A_BLINK|A_BOLD);
    attroff(COLOR_PAIR(green));

    attroff(A_REVERSE);
    refresh();
    getch();
    attron(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    printw("Welcome !");
    attroff(COLOR_PAIR(green)|A_BOLD|A_BLINK);
    getch();
    clear();
/*    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
        mvprintw();
        }
    }

*/



    endwin();

    return 0;
}
