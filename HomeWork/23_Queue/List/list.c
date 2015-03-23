#include <list.h>
void addList(ListNode **list,int data){

    ListNode *tempList=(ListNode *)malloc(sizeof(ListNode));
    tempList->data=data;
    tempList->next=*list;
    *list=tempList;
    tempList=NULL;
}


void printList(ListNode *list){
    ListNode *temp =list;
    while(temp){
        printf("%d ",temp->data+1);
        temp=temp->next;
    }
}


void dellist(ListNode **list){
 ListNode *temp;
    while(*list!=NULL){
        temp=(*list)->next;
        free(*list);
        *list=temp;
    }
}

int popList(ListNode **list){
    ListNode *temp=NULL;
    int value;
    if(list==NULL){
        exit(-1);
    }
    temp=*list;
    value=temp->data;
    *list=(*list)->next;
    free(temp);
    return value;
}

int collNode(ListNode *list){
    int result=0;
    ListNode *temp;
    while(list){
        temp=list->next;
        result++;
        list=temp;
    }

    return result;
}

bool chekNullList(ListNode *list){
    if(list)
        return true;
    return false;

}


void addNodeToEnd(ListNode **list,int data){
    ListNode *temp=NULL,*tempList=*list;
    temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL){
        fprintf(stderr,"error");
        exit(1);
    }
    temp->data=data;
    temp->next=NULL;
    if(tempList==NULL){
        *list=temp;
    }else{
        while(tempList->next!= NULL)
                   tempList = tempList->next;
               tempList->next = temp;
           }

           temp= NULL;



}

