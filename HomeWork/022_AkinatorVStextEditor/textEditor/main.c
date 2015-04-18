#include <stdio.h>
#include <stdlib.h>
#include "textEditor.h"

int main()
{
    int maxCol, maxRow, col = 0, row = 0;
    Work status = work;
    initialiseProgram();
    sizeWindow(&maxCol, &maxRow);    // row - strok
    ListAllNode *text = NULL;
    text = initListTextEditor(maxRow);
    maxCol -= 1; //wtf mode
    BufferNode **bufer = NULL;   //  mb no row&?
    addNode(text, ' ');  //// vremenno
    showTextEditor(text, maxRow);
    maxCol = 5; //temp max Col data

    while(status != exits)
    {
        keypad(stdscr, true);

        int action = getch();

        switch(action)
        {
        case KEY_UP:
            upOperation(text);
            break;

        case KEY_DOWN:
            downOperation(text);
            break;

        case KEY_LEFT:
            leftOperation(text);
            break;

        case KEY_RIGHT:
            rightOperation(text);
            break;

        case 10:
            pressEnter(text); //press Enter
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
            enterData(text, action);



            break;
        }

        showTextEditor(text, maxRow);



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
