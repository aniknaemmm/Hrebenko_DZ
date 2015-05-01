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
        generateList->tail = tempList;
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

            // one element
            // one element-->>two elemetn
            // one element || two element || three element
            list->string->flag = nocurs;
            nodeData->flag = curs;
            nodeData->head = list->string;

            if(list->string->next == NULL)   nodeData->tail = nodeData; // for one element string
            else nodeData->tail = list->string->tail;

            nodeData->link = list->string;
            nodeData->next = list->string->next;

            if(list->string->next != NULL) list->string->next->link = nodeData; //если есть следующий элемент то привязываем к нему вставленный элемент

            list->string->next = nodeData;
            nodeData->text = list->string->text;
            list->string->text = data;
            list->string = nodeData;
        }
        else
        {
            // nodeData->flag = curs;
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
    //сдвиг текста на новую строку при написание + учёт границ!!(доделать)

    addNode(list, data);


}
void showTextEditor(ListAllNode *list, int maxRow)
{
    assert(list);
    ListAllNode *rowList = NULL;
    Node *tempString = NULL;
    int col = 0, exit = 0;
    rowList = list->head;
    tempString = list->head->string->head;

    for(int row = 0; row < maxRow; row++)
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

        if(rowList->next != NULL)
        {
            rowList = rowList->next;

            if(rowList->string != NULL)
                tempString = rowList->string->head;
        }
    }

    //-----------costil



    //-------------
    refresh();

}

int chekCol(ListAllNode *listTemp)
{
    assert(listTemp);
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

    list = NULL;
    return col;
}

int chekMaxColPosition(ListAllNode *listTemp)
{
    assert(listTemp);
    Node *list = listTemp->string->tail;

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

bool backSpace(ListAllNode **list)//доработать
{
    Node *position = (*list)->string->link;
    Node *temp;

    if(position == NULL)
    {
        return false;
    }
    else
    {


        // one
        // one <-- two
        // one <-- two <-- three


        if(position->link != NULL) position->link->next = position->next;

        position->next->link = position->link;
        temp = position;
        free(temp);
        position = NULL;
    }

    return true;
}



bool leftOperation(ListAllNode **list)
{
    Node *position = (*list)->string;

    if(position->link == NULL)
    {
        if((*list)->link == NULL)
            return false;

        position->flag = nocurs;
        (*list) = (*list)->link;
        (*list)->string = (*list)->string->tail;
        (*list)->string->flag = curs;
    }
    else
    {
        position->flag = nocurs;
        (*list)->string = (*list)->string->link;
        (*list)->string->flag = curs;
    }

    return true;
}

bool upOperation(ListAllNode **list)
{
    int pos; //временная переменная для записи позиции при перемещение курсора

    if((*list)->link == NULL)
        return false;

    else
    {
        if(chekCol(*list) > chekMaxColPosition((*list)->link))
        {
            (*list)->string->flag = nocurs;
            (*list) = (*list)->link;
            (*list)->string = (*list)->string->tail;
            (*list)->string->flag = curs;
        }
        else
        {
            pos = chekCol(*list) - 1;
            (*list)->string->flag = nocurs;
            (*list) = (*list)->link;
            (*list)->string = (*list)->string->head;

            while(pos)
            {
                (*list)->string = (*list)->string->next;
                pos--;
            }

            (*list)->string->flag = curs;

        }
    }

    return true;
}

bool rightOperation(ListAllNode **list)
{
    if(((*list)->string->next == NULL))
    {
        if((*list)->next->string == NULL)
            return false;

        (*list)->string->flag = nocurs;
        (*list) = (*list)->next;
        (*list)->string = (*list)->string->head;
        (*list)->string->flag = curs;
    }
    else
    {
        (*list)->string->flag = nocurs;
        (*list)->string = (*list)->string->next;
        (*list)->string->flag = curs;
    }

    return true;
}

bool downOperation(ListAllNode **list)
{
    int pos; //временная переменная для записи позиции при перемещение курсора

    if(((*list)->next == NULL) || ((*list)->next->string == NULL))
        return false;
    else
    {
        if(chekCol(*list) > chekMaxColPosition((*list)->next))
        {
            (*list)->string->flag = nocurs;
            (*list) = (*list)->next;
            (*list)->string = (*list)->string->tail;
            (*list)->string->flag = curs;
        }
        else
        {
            pos = chekCol(*list) - 1;
            (*list)->string->flag = nocurs;
            (*list) = (*list)->next;
            (*list)->string = (*list)->string->head;

            while(pos)
            {
                (*list)->string = (*list)->string->next;
                pos--;
            }

            (*list)->string->flag = curs;

        }
    }

    return true;
}



void pressEnter(ListAllNode **list) //встовляет строку?
{



    if((*list)->next != NULL)
    {
        if((*list)->next->string == NULL)
        {
            (*list)->string->flag = nocurs;
            (*list) = (*list)->next;
            addNode(*list, ' ');
        }
    }


}

void cleanList(ListAllNode **list)
{
    (*list) = (*list)->head;
    system("clear");
    Node *clear;
    Node *string = (*list)->string->head;
    int exit = 0;

    while(!exit)
    {

        while(string)
        {
            clear = string;
            string = string->next;
            free(clear);
        }


        if((*list)->next == NULL)
            exit = 1;
        else
            (*list) = (*list)->next;
    }

    addNode((*list)->head, ' ');
    (*list) = (*list)->head;
}


void writeToFile(ListAllNode *list, FILE *file, int maxRow)
{


    ListAllNode *rowList = NULL;
    Node *tempString = NULL;
    int exit = 0, col = 0;
    rowList = list->head;

    while(!exit)
    {

        col++;

        if(rowList->next->string == NULL)
            exit = 1;
        else
            rowList = rowList->next;

    }

    fprintf(file , "%d ", col);

    rowList = list->head;
    tempString = list->head->string->head;
    exit = 0;

    for(int row = 0; row < maxRow; row++)
    {
        while(!exit && (rowList->string != NULL))
        {
            fprintf(file , "%c", tempString->text);

            if(tempString->next == NULL)
                exit = 1;
            else
                tempString = tempString->next;

        }

        fprintf(file , "\n");
        exit = 0;

        if(rowList->next != NULL)
        {
            rowList = rowList->next;

            if(rowList->string != NULL)
                tempString = rowList->string->head;
        }
    }
}

void rInfoFile(ListAllNode **list, FILE *file, int maxCol)
{
    int size;// сколько строк считать
    fscanf(file , "%d " , &size);// читаем из файла
    //проверка на перепонение!
    char data;
    // cleanList(list);  //очистка листа для загрузки из файла а пока только один раз открыть
    (*list) = (*list)->head;

    while(size)
    {
        for(int i = 0; (i < maxCol) && (data != '\n'); i++)
        {
            data = fgetc(file);

            if(data == '\n')
            {
                (*list)->string->flag = nocurs;

                if((*list)->next != NULL)(*list) = (*list)->next;

                addNode(*list, ' ');
            }
            else
            {
                addNode(*list, data);
            }

        }

        size--;
        data = 0;

    }
}




