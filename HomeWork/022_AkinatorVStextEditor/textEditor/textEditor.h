#ifndef TEXTEDITOR_H_INCLUDED
#define TEXTEDITOR_H_INCLUDED
#include "../../../modules/include/ncursesinit.h"
typedef enum Flags_ {nocurs = 0, curs} Flag;
typedef enum Head_  {head = 0, nohead} Head;
typedef enum Work_  {work = 0, exits} Work;

typedef struct Node_
{
    char text;
    int position;
    Flag flag;
    struct Node_ *head;
    struct Node_ *tail;
    struct Node_ *link;
    struct Node_ *next;

} Node;

typedef struct BufferNode_
{
    char   text;
    int    numbAllBufferNode;
    struct BufferNode_ *link;
    struct BufferNode_ *next;

} BufferNode;

typedef struct ListAllNode_
{

    struct ListAllNode_ *head;
    struct ListAllNode_ *tail;
    struct ListAllNode_ *link;
    struct ListAllNode_ *next;
    struct Node_ *string; // почему в это структуре надо использовать Node_ !!
} ListAllNode;

ListAllNode *initListTextEditor(int row);
void sizeWindow(int *cols, int  *row);
void enterData(ListAllNode *list, char data);
void addNode(ListAllNode *list, char data);
void showTextEditor(ListAllNode *list, int maxRow);
bool rowPosition(ListAllNode *list);
void pressEnter(ListAllNode *list);
int chekCol(ListAllNode *listTemp);
bool upOperation(ListAllNode *list);
bool downOperation(ListAllNode *list);
bool leftOperation(ListAllNode *list);
bool rightOperation(ListAllNode *list);


int chekMaxColPosition(Node **listTemp, int row);
void dellRow(Node **list, int row);
#endif // TEXTEDITOR_H_INCLUDED
