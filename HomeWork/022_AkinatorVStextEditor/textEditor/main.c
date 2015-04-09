#include <stdio.h>
#include <stdlib.h>
#include "textEditor.h"
#include "../../../modules/include/ncursesinit.h"
int main()
{

    initialiseProgram();


    Node **text = NULL;
    Node temp;
    int x = 0;
    text = initListTextEditor();
    addNode(&text[0], 10);

    addNode(&text[1], 15);
    addNode(&text[1], 15);
    int m=text[1]->position;
   // x = text[0][0].position;
    //printf("%d", text[0][0].position);






    attron(COLOR_PAIR(blue) | A_BOLD);

    attroff(COLOR_PAIR(blue) | A_BOLD);
    getch();
    endwin();
    return 0;
}
