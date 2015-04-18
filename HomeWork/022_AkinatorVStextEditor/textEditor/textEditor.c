#include "textEditor.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <assert.h>
void sizeWindow(int *cols, int  *row)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    *row = size.ws_row;
    *cols = size.ws_col;
}


ListAllNode *initListTextEditor(int row)
{
    ListAllNode *tempList = NULL;

    tempList = (ListAllNode *)malloc(sizeof(ListAllNode));

    if(tempList == NULL)
    {
        fprintf(stderr, "errr memory");
        exit(-2);
    }

    tempList->head = tempList;
    tempList->tail = tempList;
    tempList->link = NULL;
    tempList->next = NULL;
    tempList->string = NULL;
    ListAllNode *generateList = tempList;
    tempList = NULL;

    for(int i = 0; i < (row - 1); i++)
    {
        tempList = (ListAllNode *)malloc(sizeof(ListAllNode));

        if(tempList == NULL)
        {
            fprintf(stderr, "errr memory");
            exit(-2);
        }

        tempList->head = generateList->head;
        tempList->link = generateList;
        tempList->next = NULL;
        tempList->tail = tempList;
        tempList->string = NULL;
        generateList->next = tempList;
        generateList = generateList->next;
        tempList = NULL;
    }

    return generateList->head;

}

void addNode(ListAllNode *list, char data)
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


    if(list->string == NULL)
    {
        nodeData->flag = curs;
        nodeData->head = nodeData;
        nodeData->tail = nodeData;
        nodeData->position = 0;
        nodeData->next = NULL;
        nodeData->link = NULL;
        list->string = nodeData;
    }
    else
    {

        if(list->string->link == NULL)
        {
            nodeData->head = nodeData;
            list->string->head = nodeData;
            nodeData->next = list->string;
            nodeData->link = NULL;
            nodeData->tail = list->string->tail;
            list->string->head = nodeData;
            list->string->link = nodeData;
        }
        else
        {
            nodeData->head = list->string->head;
            list->string->link->next = nodeData;
            nodeData->link = list->string->link;
            nodeData->next = list->string;
            nodeData->tail = list->string->tail;
            list->string->link = nodeData;
        }

        //nodeData->position = chekCol(list, row);
    }


    nodeData = NULL;
}

void enterData(ListAllNode *list, char data)
{
    //сдвиг текста на новую строку при написание + учёт границ

    addNode(list, data);


}
void showTextEditor(ListAllNode *list, int maxRow)
{
    ListAllNode *rowList = NULL;
    Node *tempString = NULL;
    int col = 0, exit = 0;
    rowList = list->head;
    tempString = list->head->string->head;

    for(int row = 0; row < maxRow - 1; row++)
    {
        while(!exit && (rowList->string != NULL))
        {
            if(tempString->flag != curs)
            {
                move(row, col);
                col++;
                printw("%c", tempString->text);

            }
            else
            {
                move(row, col);
                col++;
                attron(A_REVERSE);
                printw("%c", tempString->text);
                attroff(A_REVERSE);
            }

            if(tempString->next == NULL)
                exit = 1;
            else
                tempString = tempString->next;

        }

        exit = 0;
        col = 0;
        rowList = rowList->next;

        if(rowList->string != NULL)
            tempString = rowList->string->head;
    }

    //-----------costil



    //-------------
    refresh();

}

int chekCol(ListAllNode *listTemp)
{
    Node *list = listTemp->string;
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


bool rowPosition(ListAllNode *listTemp)
{
    assert(listTemp);
    Node *list = listTemp->string->head;
    int exit = 0;
    int col = 0;

    while(!exit)
    {
        col++;

        if(list->next == NULL)
            exit = 1;
        else
            list = list->next;
    }

    return false;

}

bool leftOperation(ListAllNode *list)
{
    Node *position = list->string;

    if(position->link == NULL)
    {
        if(list->link == NULL)
            return false;

        position->flag = nocurs;
        list = list->link;
        list->string = list->string->tail;
        list->string->flag = curs;
    }
    else
    {
        position->flag = nocurs;
        list->string = list->string->link;
        list->string->flag = curs;
    }

    return true;
}

bool upOperation(ListAllNode *list)
{


    if(list->link == NULL)
        return false;

    /*  else
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
              pos = chekCol(list, *row) - 1;
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
      }*/

    return true;
}

bool rightOperation(ListAllNode *list)
{
    if((list->string->next == NULL))
    {
        if(list->next == NULL)
            return false;

        list->string->flag = nocurs;
        list = list->next;
        list->string = list->string->head;
        list->string->flag = curs;
    }
    else
    {
        list->string->flag = nocurs;
        list->string = list->string->next;
        list->string->flag = curs;
    }

    return true;
}

bool downOperation(ListAllNode *list)
{
    int pos;

    /*  if(list[*row + 1] == NULL)
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
              pos = chekCol(list, *row) - 1;
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
      }*/

    return true;
}



void pressEnter(ListAllNode *list) //встовляет строку
{

    list->string->flag = nocurs;

    if(list->next != NULL)
    {
        list = list->next;

        addNode(list, ' ');
    }

// else
//{
//}
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

