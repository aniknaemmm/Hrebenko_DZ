#ifndef CALC_H
#define CALC_H


    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    #define SIZE 500

typedef enum Flags_ {numb=1,deistvie} Flag;

typedef struct Simvol_{
    double numb;
    char znak;
    Flag status;
}Simvol;

typedef struct Node_{
    Simvol data;
    struct Node_ *link;

}Node;

void initALL(Node **list);
void addNodeHead(Node **list,Simvol data);
void addNodeTail(Node **list, Simvol data);
void popFront(Node **list);
int  chekPriority(char *znak);
void dellList(Node **list);
void toPostfix(Node **postFix,char *string,Node **stack);
void initNumber(Simvol *temp,double number);
void initSimvol(Simvol *temp,char sim);
void gogoPostfix(Node **postFix,Node**stack);
void chekElement(Node **stack,Simvol obj);
bool chekTop(Simvol *temp,Node *stack);
void operation(Node **stack,char znak);
#endif // CALC_H

/*1*2+3+4*5
12+3+45*+

12
+
12+
3
+
12+3+
45
*
12+3+45**/
