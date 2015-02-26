#include <ncurses.h>
<<<<<<< HEAD
#include <locale.h>    //kodirovka?
static char unusedCell[4] = "\342\227\206";
enum Colors{normal, green, red,yellow}; // perechislenie cvetov
void treatSigWinch(int signo);
static int upDown = 0, leftRight = 0;
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
{int rows,cols;
rows=20;
cols=20;
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
    for(int i=0;i<4;i++){
            for(int k=0;k<4;k++){
    mvprintw(i,k,"!");
    }}
      refresh();
    getch();
    mvprintw(2,2,"0");
     refresh();
    getch();
keypad(stdscr, true);
    int symbol = getch();
    switch(symbol)
    {
    case KEY_UP:
        if(upDown == 0 && leftRight == 0)
        {
            upDown = rows - 1;
            leftRight = cols - 1;
        }
        else if(upDown == 0)
        {
            upDown = rows - 1;
            --leftRight;
        }
        else
        {
            --upDown;
        }
        break;
    case KEY_DOWN:
        if(upDown == rows - 1 && leftRight == cols - 1)
        {
            upDown = 0;
            leftRight = 0;
        }
        else if(upDown == rows - 1)
        {
            upDown = 0;
            ++leftRight;
        }
        else
        {
            ++upDown;
        }
        break;
    case KEY_LEFT:
        if(upDown == 0 && leftRight == 0)
        {
            upDown = rows - 1;
            leftRight = cols - 1;
        }
        else if(leftRight == 0)
        {
            --upDown;
            leftRight = cols - 1;
        }
        else
        {
            --leftRight;
        }
        break;
    case KEY_RIGHT:
        if(upDown == rows - 1 && leftRight == cols - 1)
        {
            upDown = 0;
            leftRight = 0;
        }
        else if(leftRight == cols - 1)
        {
            ++upDown;
            leftRight = 0;
        }
        else
        {
            ++leftRight;
        }
        break;
    }

        endwin();

    return 0;
=======
#include <ctype.h>

int main(void)
{
	WINDOW *left,*right;
	int maxx,maxy,halfx;
	int ch;

	initscr();
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_RED);

/* calculate window sizes and locations */
	getmaxyx(stdscr,maxy,maxx);
	halfx = maxx >> 1;						/* half the screen width */

/* create the two side-by-side windows */
	if( (left = newwin(maxy,halfx,0,0)) == NULL)
	{
		endwin();
		puts("Unable to create 'left' window");
		return 1;
	}
	if( (right = newwin(maxy,halfx,0,halfx)) == NULL)
	{
		endwin();
		puts("Unable to create 'right' window");
		return 1;
	}

/* Set up each window */
	mvwaddstr(left,0,0,"Left window (type ~ to end)\n");
	wbkgd(left,COLOR_PAIR(1));
	wrefresh(left);
	mvwaddstr(right,0,0,"Right window\n");
	wbkgd(right,COLOR_PAIR(2));
	wrefresh(right);

/* Read keyboard and update each window */
	do
	{
		ch = wgetch(left);					/* read/refresh left window */
		if(isalpha(ch))
		{
			if(toupper(ch)>='A' && toupper(ch)<='M')
				ch += 13;
			else
				ch -= 13;
		}
		waddch(right,ch);					/* write/refresh right window */
		wrefresh(right);
	} while(ch != '~');

	endwin();
	return 0;
>>>>>>> 1cc84bb88783dc255187f27983cbff96a7654981
}
