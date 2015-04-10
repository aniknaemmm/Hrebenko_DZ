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

    nodeData->text = data;
    nodeData->link = list[row];
    nodeData->flag = curs;
    //

    if(list[row] == NULL)
    {
        nodeData->position = 0;
        nodeData->next = NULL;
    }
    else
    {
        list[row]->flag = nocurs;
        nodeData->next = list[row]->next;
        list[row]->next = nodeData;
        nodeData->position = list[row]->position + 1;
    }

    if(row)
        list[row - 1]->flag = nocurs;

    list[row] = nodeData;
    nodeData = NULL;
}

void enterData(Node **list, int row, char data)
{

    addNode(list, row, data);

    /*if(*colPos == maxCol)
    {
        *colPos = 0;
        *rowPos += 1;
    }*/

//------------
//обработка исключений при вводе
    //
//-----------
}
/*
Node **copyDinArray(const Node **list, int row)
{
    Node **copyList = NULL;
    copyList = (Node **)malloc(row * sizeof(Node *));

    if(tempList == NULL)
    {
        fprintf(stderr, "errr memory");
        exit(-2);
    }

    for(int y = 0; y < maxRow; y++)
    {
        while(list[y] != NULL && list[y]->link != NULL)
        {
            list[y] = list[y]->link;
        }
    }


    for(int i = 0; i < row; i++)
    {
        while()


    }




    return copyList;
}*/

void showTextEditor(Node **list, int row , int maxRow, int maxCol)
{


    move(row, chekCol(list, row));
    printw("%c", list[row]->text);

    if(chekCol(list, row) < maxCol)
    {
        move(row, chekCol(list, row) + 1);
        attron(A_REVERSE);
        printw(" ");
        attroff(A_REVERSE);
    }
    else
    {
        move(row + 1, 0);
        attron(A_REVERSE);
        printw(" ");
        attroff(A_REVERSE);
    }

    refresh();

}

int chekCol(Node **list, int row)
{
    int end = 0;
    int col = 0;

    while(list[row] != NULL && list[row]->link != NULL)
    {
        col++;
        list[row] = list[row]->link;
    }

    while(!end)
    {

        if(list[row]->next == NULL)
        {
            end = 1;
        }
        else
        {
            list[row] = list[row]->next;
        }
    }

    return col;
}

bool rowPosition(Node **list, int maxCol, int row)
{
    if(chekCol(list, row) >= maxCol)
        return true;

    return false;

}

void leftOperation(Node **list, int *row)
{
    if((chekCol(list, *row) == 0) && *row != 0)
    {
        (*row) -= 1;
    }
    else

        list[*row] = list[*row]->link;



}
void pressEnter(Node **list, int *row,int maxRow)//встовляет строку
{    *row+=1;
    for(int i=*row;i<maxRow-1;i++)
        list[*row+1]=list[*row];

   addNode(list,*row,' '); //работа в показе с нул
}
