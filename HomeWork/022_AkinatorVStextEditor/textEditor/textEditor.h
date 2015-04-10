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



Node **initListTextEditor(int row);
void addNode(Node **list, int row , char data);
void sizeWindow(int *cols, int  *row);
void showTextEditor(Node **list, int row , int maxRow, int maxCol);
void enterData(Node **list, int row, char data);
bool rowPosition(Node **list, int maxCol, int row);
int chekCol(Node **list, int row);
void leftOperation(Node **list, int *row);
void pressEnter(Node **list, int *row,int maxRow);
#endif // TEXTEDITOR_H_INCLUDED
