#include "calc.h"

void initALL(Node **list){
    *list=NULL;
    }
void addNodeHead(Node **list,Simvol data){
    Node *temp=(Node *)malloc(sizeof(Node));
    if(temp==NULL){
        fprintf(stderr,"error memory is full");
        exit(-1);
    }
    temp->data=data;
    temp->link=*list;
    *list=temp;
    temp=NULL;

}

void addNodeTail(Node **list, Simvol data){
    Node *temPoint=*list;
    Node *temp=(Node *)malloc(sizeof(Node));
    if(temp==NULL){
        fprintf(stderr,"memory is full");
        exit(-1);
    }
    temp->data=data;
    temp->link=NULL;
    if(*list==NULL)
        *list=temp;
    else{
        while(temPoint->link!=NULL)
            temPoint=temPoint->link;
        temPoint->link=temp;
    }
    temp=NULL;

}

void popFront(Node **list){
    Node *temp;
    if(*list==NULL){
        fprintf(stderr,"memory is full");
        exit(-1);
    }
    temp=*list;
    (*list)=(*list)->link;
    free(temp);
    temp=NULL;

}

int chekPriority(char *znak){
    if(*znak=='+'||*znak=='-')
        return 1;
    if(*znak=='*'||*znak=='/')
        return 2;
    if(*znak=='^')
        return 3;
    if(*znak=='('||*znak==')')
        return 0;
    fprintf(stderr,"error Inalid value:\n");
    exit(-2);



}


void dellList(Node **list){
    Node *temp;
    while(*list!=NULL){
        temp=(*list)->link;
        free(*list);
        *list=temp;
    }

}

void  initSimvol(Simvol *temp,char sim){
    temp->status=deistvie;
    temp->znak=sim;
}

void initNumber(Simvol *temp,double number){
    temp->status=numb;
    temp->numb=number;
}

bool chekTop(Simvol *temp,Node *stack){
    if(stack==NULL)
        return false;
    *temp=stack->data;
    return true;
}

void toPostfix(Node **postFix,char *string,Node **stack){

    double tempNumb;
    Simvol result;
    char *workString=string;
    while (*workString!='\n'||*workString!=' '){
        if(*workString=='('){
        initSimvol(&result,*workString);
        addNodeHead(stack,result);
        }
        else if(*workString==')'){
                while(chekTop(&result,*stack)&&chekPriority(&result.znak)>chekPriority(workString)){
                    addNodeHead(postFix,result);
                    popFront(stack);
                }
                popFront(stack);

        }else if(strchr("^+-/*",*workString)){
                while(chekTop(&result,*stack)&&chekPriority(&result.znak)>=chekPriority(workString)){
                    addNodeHead(postFix,result);
                    popFront(stack);
                }
                initSimvol(&result,*workString);
                addNodeHead(stack,result);

        }else{
            tempNumb=strtod(workString,&workString);
            initNumber(&result,tempNumb);
            addNodeHead(postFix,result);
            workString--;
        }
        workString++;
    }

    while(chekTop(&result,*stack)){
        addNodeHead(postFix,result);
        popFront(stack);
    }

}
void chekElement(Node **stack,Simvol obj){
    if(obj.status==numb){
        addNodeHead(stack,obj);
    }else{
        operation(stack,obj.znak);
    }

}

void gogoPostfix(Node **postFix,Node**stack){
    Node *tempList=*postFix;
    while(tempList){
        chekElement(stack,tempList->data);
        tempList=tempList->link;
    }

}

void operation(Node **stack,char znak){
    Simvol first,next,result;
    chekTop(&first,*stack);
    popFront(stack);
    chekTop(&next,*stack);
    popFront(stack);

    if(znak=='+')
        result.numb=first.numb+next.numb;
    if(znak=='-')
        result.numb=first.numb-next.numb;
    if(znak=='*')
        result.numb=first.numb*next.numb;
    if(znak=='/')
        result.numb=first.numb/next.numb;
    if(znak=='^')
        result.numb=pow(next.numb,first.numb);
    addNodeHead(stack,result);

}

