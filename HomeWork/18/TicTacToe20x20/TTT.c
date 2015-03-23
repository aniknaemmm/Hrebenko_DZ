#include "TTT.h"
#include "../../modules/include/ncursesinit.h"
#define SIZE 20
static int row=0,cols=0;
static int temp_row=0,temp_cols=0;
static int ticta=0;

void drawTable(int mass[][SIZE])
{
    attron(COLOR_PAIR(red));
    for(int i=0; i<SIZE; i++)
    {
        for(int k=0; k<SIZE; k++)
        {
            mvprintw(i,k,"#");
        }
    }
    attroff(COLOR_PAIR(red));
    attron(A_REVERSE);
    mvprintw(row,cols,"#");
    attroff(A_REVERSE);
    refresh();
}

void drwka(int mass[][SIZE])
{
    attron(A_REVERSE);
    if(mass[row][cols]==0) mvprintw(row,cols,"#");
    if(mass[row][cols]==1) mvprintw(row,cols,"o");
    if(mass[row][cols]==2) mvprintw(row,cols,"x");
    attroff(A_REVERSE);
    attron(COLOR_PAIR(blue));
    if(mass[temp_row][temp_cols]==0) mvprintw(temp_row,temp_cols,"#");
    if(mass[temp_row][temp_cols]!=0&&(temp_row!=row||temp_cols!=cols))
    {
        if(mass[temp_row][temp_cols]==1)
            mvprintw(temp_row,temp_cols,"o");
        if(mass[temp_row][temp_cols]==2)
            mvprintw(temp_row,temp_cols,"x");

    }
    attroff(COLOR_PAIR(blue));
    refresh();
    temp_cols=cols;
    temp_row=row;
}


void playGame(int mass[][SIZE])
{
    keypad(stdscr, true);
    int action = getch();
    switch(action)
    {
    case KEY_UP:
        if(row == 0)
        {
            row=SIZE-1;
        }
        else
        {
            --row;
        }
        break;
    case KEY_DOWN:
        if(row == SIZE-1)
        {
            row=0;
        }
        else
        {
            ++row;
        }
        break;
    case KEY_LEFT:
        if(cols==0)
        {
            cols=SIZE-1;
        }

        else
        {
            --cols;
        }
        break;
    case KEY_RIGHT:
        if(cols==SIZE-1)
        {
            cols=0;
        }

        else
        {
            ++cols;
        }
        break;
    case 111:
        if(mass[row][cols] == 0)
        {
            mass[row][cols] = 1;
            ticta++;
        }
        break;
    case 120:
        if(mass[row][cols] == 0)
        {
            mass[row][cols] = 2;
            ticta++;
        }
        break;
    }
    drwka(mass);
}

int chekWinGame(int mass[][SIZE])
{
    int xx,yy;
    int flags_chek=0;
    for(int k=0; k<SIZE; k++)
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int m=-1; m<2; m++)
            {
                for(int n=-1; n<2; n++)
                {
                    if(mass[i][k]!=0)
                    {
                        flags_chek=0;
                        xx=i;
                        yy=k;
                        for(int p=0; p<4; p++,xx+=m,yy+=n)
                        {
                            if(mass[i][k]==mass[xx+m][yy+n]&&!(n==0&&m==0)) flags_chek++;
                            if(flags_chek==4) return mass[i][k];
                        }
                    }
                }
            }
        }
    }
    if(ticta==SIZE*SIZE-4) return -1;
    return 0;
}




