#include <list.h>
void addList(ListNode **list,int data){

    ListNode *tempList=(ListNode *)malloc(sizeof(ListNode));
    tempList->data=data;
    tempList->next=*list;
    *list=tempList;


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

