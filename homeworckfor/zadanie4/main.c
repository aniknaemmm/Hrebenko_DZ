#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int secretNumb,interNumb,i=0,y;
    srand(time(NULL));
    do{
    secretNumb=rand()%100;
    printf("Hello\nI want to play with you\n");
    do
    {
        printf("enter numb   ");
        scanf("%d",&interNumb);
        i++;
        if(secretNumb>interNumb)
        {
            printf("bolshe\n");
        }
        else if(secretNumb<interNumb)
        {
            printf("men'she\n");
        }
    }
    while(!(secretNumb==interNumb));
    printf("good %c\n my number %d  attempts %d",2,secretNumb,i);
    printf("esli budesh vvedi 1 esli net to q =");
    }while(scanf("%d",&y));

    return 0;
}
