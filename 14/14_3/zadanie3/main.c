#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../modules/include/dices.h"
int main()
{
    srand(time(NULL));
    printf("Hello world!\n");
    int compNumber,userNumber;
    char answer;
    do
    {
        system("cls");
        printf("hello \n chto bi kinut' nagmi knopku lubuiu\n");
        getchar();
        kubikRubickSmutik(userNumber=1+rand()%6);
        printf("seichas komp kinet");
        getchar();
        kubikRubickSmutik(compNumber=1+rand()%6);
        getchar();
        if(userNumber!=compNumber)printf("i tak user %c comp\n",userNumber>compNumber?'>':'<');
        else printf("nich9\n");
        printf("kidanut' esho kubikov>?(y/n)");
        scanf("%c",&answer);
    }
    while(answer=='y');

    return 0;
}
