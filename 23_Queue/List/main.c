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
    printList(head);

      printf("\nHello World!\n%d\n",popList(&head));
        printList(head);
    return 0;
}

