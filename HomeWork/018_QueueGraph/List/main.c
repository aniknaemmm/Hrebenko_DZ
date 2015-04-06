#include "list.h"

int main(void)
{
    printf("Hello World!\n");

    ListNode *head;
    head=NULL;
    int k=10;
    addList(&head,k);
    addList(&head,k);
    addList(&head,k);
    addNodeToEnd(&head,k);
    printList(head);

      printf("\nHello World!\n%d\n",collNode(head));
        printList(head);
    return 0;
}

