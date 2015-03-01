#include "TTTxo.h"
#include "../../modules/include/ncursesinit.h"
static int row=0,cols=0,layer=0;
static int temp_row=0,temp_cols=0,temp_layer=0;
static int ticta=0;


void drawTable(int mass[][SIZE][SIZE])
{
    attron(COLOR_PAIR(red));

    for(int x=0; x<SIZE; x++)
    {
        for(int y=0; y<SIZE; y++)
        {
            printw("#");
        }
        printw("\n");
    }

    attroff(COLOR_PAIR(red));
    attron(A_REVERSE);
    mvprintw(row,cols,"#");
    attroff(A_REVERSE);
    attron(COLOR_PAIR(red)|A_BLINK);
    mvprintw(2,6,"layer level %d",layer);
    attroff(COLOR_PAIR(red)|A_BLINK);
    refresh();
}

void drwka(int mass[][SIZE][SIZE])
{
    attron(A_REVERSE);
    if(mass[row][cols][layer]==0) mvprintw(row,cols,"#");
    if(mass[row][cols][layer]==1) mvprintw(row,cols,"o");
    if(mass[row][cols][layer]==2) mvprintw(row,cols,"x");
    attroff(A_REVERSE);
    attron(COLOR_PAIR(blue));
    if(mass[temp_row][temp_cols][temp_layer]==0) mvprintw(temp_row,temp_cols,"#");
    if(mass[temp_row][temp_cols][temp_layer]!=0&&(temp_row!=row||temp_cols!=cols||temp_layer!=layer))
    {
        if(mass[temp_row][temp_cols][temp_layer]==1)
            mvprintw(temp_row,temp_cols,"o");
        if(mass[temp_row][temp_cols][temp_layer]==2)
            mvprintw(temp_row,temp_cols,"x");

    }
    attroff(COLOR_PAIR(blue));
    refresh();
    temp_cols=cols;
    temp_row=row;
}

void refreshDraw(int mass[][SIZE][SIZE])
{
    attron(COLOR_PAIR(red));
    for(int x=0; x<SIZE; x++)
    {
        for(int y=0; y<SIZE; y++)
        {
            if(x==row&&y==cols) attron(A_REVERSE);
            if(mass[x][y][layer]==0) mvprintw(x,y,"#");
            if(mass[x][y][layer]==1) mvprintw(x,y,"o");
            if(mass[x][y][layer]==2) mvprintw(x,y,"x");
            if(x==row&&y==cols) attroff(A_REVERSE);
        }
        printw("\n");
    }
    attroff(COLOR_PAIR(red));
    /*attron(A_REVERSE);
            if(mass[row][cols][layer]==0) mvprintw(row,cols,"#");
            if(mass[row][cols][layer]==1) mvprintw(row,cols,"o");
            if(mass[row][cols][layer]==2) mvprintw(row,cols,"x");
    attroff(A_REVERSE);*/
    temp_layer=layer;
    attron(COLOR_PAIR(red)|A_BLINK);
    mvprintw(2,6,"layer level %d",layer);
    attroff(COLOR_PAIR(red)|A_BLINK);
    refresh();
}

void playGame(int mass[][SIZE][SIZE])
{
    keypad(stdscr, true);
    int action = getch();
    switch(action)
    {
    case KEY_UP:
        if(row == 0) row=SIZE-1;
        else --row;
        break;
    case KEY_DOWN:
        if(row == SIZE-1) row=0;
        else ++row;
        break;
    case KEY_LEFT:
        if(cols==0) cols=SIZE-1;
        else --cols;
        break;
    case KEY_RIGHT:
        if(cols==SIZE-1) cols=0;
        else ++cols;
        break;
    case 100:
        if(layer == 0) layer=SIZE-1;
        else --layer;
        break;
    case 117:
        if(layer ==SIZE-1)
        {
            layer=0;
        }
        else
        {
            layer++;
        }
        break;
    case 111:
        if(mass[row][cols][layer] == 0)
        {
            mass[row][cols][layer] = 1;
            ticta++;
        }
        break;
    case 120:
        if(mass[row][cols][layer] == 0)
        {
            mass[row][cols][layer] = 2;
            ticta++;
        }
        break;
    }
    drwka(mass);
    if(temp_layer!=layer)
    {
        refreshDraw(mass);
    }
}

int chekWinGame(int mass[][SIZE][SIZE])
{
    int zg,kg,ig,flags;
    for(int m=0; m<3; m++)//proveriaem 3 ploskosti
    {
        for(int y=0; y<SIZE; y++)
        {
            for(int x=0; x<SIZE; x++)
            {
                for(int vi= -1; vi<2; vi++) //vi,vz,vk eto nashi vektora
                {
                    for(int vz=-1; vz<2; vz++)
                    {
                        for(int vk=-1; vk<2; vk++)
                        {
                            if(m==0)
                            {
                                zg=0;
                                kg=y;
                                ig=x;
                            }
                            if(m==1)
                            {
                                zg=y;
                                kg=x;
                                ig=0;
                            }
                            if(m==2)
                            {
                                zg=x;
                                kg=0;
                                ig=y;
                            }
                            flags=0;
                            if(mass[zg][kg][ig]!=0)
                            {
                                for(int p=0; p<SIZE&&((zg+vi>=0)&&(kg+vz>=0)&&(ig+vk>=0))&&((zg+vi<SIZE)&&(kg+vz<SIZE)&&(ig+vk<SIZE)); p++,zg+=vi,kg+=vz,ig+=vk)
                                {
                                    if(mass[zg][kg][ig]==mass[zg+vi][kg+vz][ig+vk]&&!(vi==0&&vz==0&&vk==0)) flags++;
                                    if(flags==3)return mass[zg][kg][ig];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ticta==SIZE*SIZE*SIZE) return -1;
    return 0;
}
