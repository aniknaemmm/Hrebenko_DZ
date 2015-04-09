#ifndef TEXTEDITOR_H_INCLUDED
#define TEXTEDITOR_H_INCLUDED
typedef enum Flags_ {nocurs=0,curs} Flag;
typedef enum Head_ {head=0,nohead} Head;
typedef struct Node_
{
    char text;
    int position;
    Flag flag;
    Head head;
    struct Node_ *link;
    struct Node_ *next;
    struct Node_ *up;
    struct Node_ *down;
}Node;

typedef struct BufferNode_
{
    char text;
    int numbAllBufferNode;
    struct BufferNode_ *link;
    struct BufferNode_ *next;
} BufferNode;



Node **initListTextEditor();
void addNode(Node **list,int data);


#endif // TEXTEDITOR_H_INCLUDED
