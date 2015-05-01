#include <stdio.h>
#include <stdlib.h>
#include "textEditor.h"

int main()
{
    FILE *file = NULL;
    int maxCol, maxRow;
    Work status = work;
    initialiseProgram();
    sizeWindow(&maxCol, &maxRow);
    ListAllNode *text = NULL;
    text = initListTextEditor(maxRow);
    maxRow -= 1;
    //BufferNode **bufer = NULL;   //  mb no row&?
    addNode(text, ' ');  //// vremenno
    showTextEditor(text, maxRow);

    while(status != exits)
    {
        keypad(stdscr, true);

        int action = getch();

        switch(action)
        {
        case KEY_UP:
            upOperation(&text);
            break;

        case KEY_DOWN:
            downOperation(&text);
            break;

        case KEY_LEFT:
            leftOperation(&text);
            break;

        case KEY_RIGHT:
            rightOperation(&text);
            break;

        case 10:
            pressEnter(&text); //press Enter
            break;

        case 127 :
            //del symbol
            backSpace(&text);
            break;

        /*case KEY_END:
            status = exits; //close document
            break;*/

        case KEY_HOME :     // option : save

            file = fopen("../text.txt", "w");
            writeToFile(text, file, maxRow);

            fclose(file);
            move(maxRow, 0);
            printw(" save : well done");
            break;

        case KEY_END :     // option : read
            file = fopen("../text.txt", "r");

            if(file == NULL)
            {
                move(maxRow, 10);
                printw(" open :can't open");
            }

            rInfoFile(&text, file, maxCol);
            fclose(file);
            move(maxRow, 0);
            printw(" open : well done");
            break;

        default :
            enterData(text, action);



            break;
        }

        showTextEditor(text, maxRow);



    }

    getch();
    endwin();
    return 0;
}
