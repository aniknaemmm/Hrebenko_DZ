#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

динамическая структура данных
1) имеют собственную структуру прямо в процессе выполнения
2) они используют динамическую память и структуру

//-----------------------------------------------------------------
typedef struct Somthing_
{
    int x;
    struct Something_ *s;
} Something;

typedef int Data;
//-----------------------------------------------------------------
typedef struct Node_
{
    Data data;
    struct Node_ *link; //*next and *previous *left *right *chtoto;;

} Node;

//------------------------------------------------------------------
Queue-очередь
стэк на односвязном списке

void push(Node **top,Data data)
{

    Node *p=NULL;
    p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->link=*top;
    *top=p;
    p=NULL;
}
void pop(Node **top)
{


    if(*top)
    {

        Node *p=*top;
        *top=(*top)->link;
        p->data=0;
        p->link=NULL;
        free(p);
        p=NULL;
    }

}

bool onTop(Node *top, Data *data)
{

    if(!top)
        return false;
    *data=top->data;
    return true;
}

bool isEmpty(Node *top)
{
    return top==NULL;
}


void clear(Node **top)
{
    while(*top)
        pop(top);

}




