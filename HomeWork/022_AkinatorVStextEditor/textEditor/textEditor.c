#include "textEditor.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdbool.h>

void sizeWindow(int *cols, int  *row)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    *row = size.ws_row;
    *cols = size.ws_col;
}


Node **initListTextEditor(int row)
{
    Node **tempList = NULL;
    tempList = (Node **)malloc(row * sizeof(Node *));

    if(tempList == NULL)
    {
        fprintf(stderr, "errr memory");
        exit(-2);
    }

    for(int i = 0; i < row; i++)
        tempList[i] = NULL;

    return tempList;

}

void addNode(Node **list, int row , char data)
{

    Node *nodeData = NULL;
    nodeData = (Node *)malloc(sizeof(Node));

    if(nodeData == NULL)
    {
        exit(-2);

    }

    //insert enter data
    //--------
    //no insert enter data

    nodeData->text = data;


    if(list[row] == NULL)
    {
        nodeData->flag = curs;
        nodeData->head = nodeData;
        nodeData->tail = nodeData;
        nodeData->position = 0;
        nodeData->next = NULL;
        nodeData->link = NULL;
        list[row] = nodeData;
    }
    else
    {

        if(list[row]->link == NULL)
        {
            nodeData->head = nodeData;
            nodeData->next = list[row];
            nodeData->link = NULL;
            nodeData->tail = list[row]->tail;
            list[row]->head = nodeData;
            list[row]->link = nodeData;
        }
        else
        {
            nodeData->head = list[row]->head;
            list[row]->link->next = nodeData;
            nodeData->link = list[row]->link;
            nodeData->next = list[row];
            nodeData->tail = list[row]->tail;
            list[row]->link = nodeData;

        }

        nodeData->position = chekCol(list, row);

    }


    //nodeData = NULL;
}

void enterData(Node **list, int *row, char data)
{
    //сдвиг текста на новую строку при написание + учёт границ

    addNode(list, *row, data);


}

void showTextEditor(Node **list, int maxRow)
{
    Node *rowList = NULL;
    int col = 0;
    int exit = 0;

    for(int row = 0; (row < maxRow) && (list[row] != NULL); row++)
    {

        rowList = list[row]->head;

        while(!exit)
        {
            if(rowList->flag != curs)
            {
                move(row, col);
                col++;
                printw("%c", rowList->text);

            }
            else
            {
                move(row, col);
                col++;
                attron(A_REVERSE);
                printw("%c", rowList->text);
                attroff(A_REVERSE);
            }

            if(rowList->next == NULL)
                exit = 1;
            else
                rowList = rowList->next;

        }

        exit = 0;
        col = 0;

    }

    //-----------costil



    //-------------
    refresh();

}

int chekCol(Node **listTemp, int row)
{
    Node *list = listTemp[row];
    int exit = 0;
    int col = 0;

    if(list == NULL)
        return col;

    while(!exit)
    {
        col++;

        if(list->link == NULL)
            exit = 1;
        else
            list = list->link;
    }


    return col;
}

int chekMaxColPosition(Node **listTemp, int row)
{
    int exit = 0;
    int col = 0;

    if(listTemp[row] == NULL)
        return col;

    Node *list = listTemp[row]->tail;

    while(!exit)
    {
        col++;

        if(list->link == NULL)
            exit = 1;
        else
            list = list->link;
    }


    return col;
}


bool rowPosition(Node **listTemp, int maxCol, int row)
{
    Node *list = listTemp[row];
    int exit = 0;
    int col = 0;

    while(!exit)
    {
        if(list->next == NULL)
            exit = 1;
        else
            list = list->next;
    }

    if(chekCol(&list, row) >= maxCol)
        return true;

    return false;

}

bool leftOperation(Node **list, int *row)
{
    if(list[*row]->link == NULL)
    {
        if(!*row)
            return false;

        list[*row]->flag = nocurs;
        (*row) -= 1;
        list[*row] = list[*row]->tail;
        list[*row]->flag = curs;
    }
    else
    {
        list[*row]->flag = nocurs;
        list[*row] = list[*row]->link;

        list[*row]->flag = curs;
    }

    return true;
}

bool upOperation(Node **list, int *row)
{
    int pos;

    if(!*row)
        return false;
    else
    {
        if(chekCol(list, *row) > chekMaxColPosition(list, *row - 1))
        {
            list[*row]->flag = nocurs;
            *row -= 1;
            list[*row] = list[*row]->tail;
            list[*row]->flag = curs;
        }
        else
        {
            pos = chekCol(list, *row)-1;
            list[*row]->flag = nocurs;
            *row -= 1;
            list[*row] = list[*row]->head;

            while(pos)
            {
                list[*row] = list[*row]->next;
                pos--;
            }

            list[*row]->flag = curs;

        }
    }

    return true;
}

bool rightOperation(Node **list, int *row, int maxCol, int maxRow)
{
    if((list[*row]->next == NULL))
    {
        if(*row == maxRow)
            return false;

        if(list[*row + 1] == NULL)
            return false;

        list[*row]->flag = nocurs;
        (*row) += 1;
        list[*row] = list[*row]->head;
        list[*row]->flag = curs;
    }
    else
    {
        list[*row]->flag = nocurs;
        list[*row] = list[*row]->next;
        list[*row]->flag = curs;
    }

    return true;
}

bool downOperation(Node **list, int *row)
{
    int pos;

    if(list[*row+1]==NULL)
        return false;
    else
    {
        if(chekCol(list, *row) > chekMaxColPosition(list, *row + 1))
        {
            list[*row]->flag = nocurs;
            *row += 1;
            list[*row] = list[*row]->tail;
            list[*row]->flag = curs;
        }
        else
        {
            pos = chekCol(list, *row)-1;
            list[*row]->flag = nocurs;
            *row += 1;
            list[*row] = list[*row]->head;

            while(pos)
            {
                list[*row] = list[*row]->next;
                pos--;
            }

            list[*row]->flag = curs;

        }
    }

    return true;
}



void pressEnter(Node **list, int *row, int maxRow) //встовляет строку
{

    list[*row]->flag = nocurs;
    *row += 1;

    if(list[*row] == NULL)
    {
        addNode(list, *row, ' ');
    }
    else
    {
        for(int i = maxRow; (*row - 1) != i ; i--)
        {
            if(list[i] != NULL)
                list[i + 1] = list[i];
        }

        //system("clear");
        dellRow(list, *row);
        list[*row] = NULL;
        addNode(list, *row, ' ');

    }
}

void dellRow(Node **list, int row)
{
    Node *clear;

    while(list[row]->link)
    {
        clear = list[row];
        list[row] = list[row]->link;
        free(clear);
    }
}
