#include "list.h"

int main(void)
{

    printf("Hello World!\n");
    List *head=NULL;
    int k=10;
    initListTwo(&head);
    pushFront(&head,1);pushFront(&head,1);
        pushFront(&head,1);
   pushBack(head,9);
    pushBack(head,9);
     pushBack(head,9);
/*
    printf("%d\n",popFront(head));
   printf("%d\n",popFront(head));
   printf("%d\n",popFront(head));
   printf("%d\n",popFront(head));
  printf("%d\n",popFront(head));
  printf("%d\n",popFront(head));

*/   printf("%d\n",popBack(head));
     printf("%d\n",popBack(head));
     printf("%d\n",popBack(head));
     printf("%d\n",popBack(head));
     printf("%d\n",popBack(head));
     printf("%d\n",popBack(head));
     return 0;
}

