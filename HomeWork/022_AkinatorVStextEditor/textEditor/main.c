#include <stdio.h>
#include <stdlib.h>
#include "textEditor.h"

int main()
{
    int maxCol, maxRow, col = 0, row = 0;
    Work status = work;
    initialiseProgram();
    sizeWindow(&maxCol, &maxRow);    // row - strok
    Node **text = NULL;
    text = initListTextEditor(maxRow);
    maxCol-=1;//wtf mode
    BufferNode **bufer = NULL;   //  mb no row&?

    //maxCol=5;//temp max Col data
    while(status != exits)
    {
        keypad(stdscr, true);
        int action = getch();

        switch(action)
        {
        case KEY_UP:

            break;

        case KEY_DOWN:

            break;

        case KEY_LEFT:
            leftOperation(text, &row);
            break;

        case KEY_RIGHT:

            break;

        case 10:
              pressEnter(text,&row,maxRow); //press Enter
            break;

        case KEY_BACKSPACE :
            //del symbol
            break;

        case KEY_END:
            status = exits; //close document
            break;

        case KEY_SLEFT :
            //use other option : save read

            break;

        default :
            enterData(text, row, action);



            break;
        }

        showTextEditor(text,row, maxRow,maxCol);
        if(rowPosition(text, maxCol, row))
            row++;

    }

    attron(A_REVERSE);
    printw("%d %d", maxCol, maxRow);
    attroff(A_REVERSE);

    /*   attron(COLOR_PAIR(blue) | A_BOLD);

       attroff(COLOR_PAIR(blue) | A_BOLD);

    */

    getch();
    endwin();
    return 0;
}
