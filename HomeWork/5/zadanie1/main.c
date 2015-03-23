#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ostatokChisla,firstNumb,nextNumb;
    int maxNumb,minNumb;
    printf("molorik enter first=");
    scanf("%d",&firstNumb);
    printf("molorik enter next=");
    scanf("%d",&nextNumb);
    if(!nextNumb==0&&!firstNumb==0)
    {
        maxNumb=(nextNumb<firstNumb)?firstNumb:nextNumb;
        minNumb=(nextNumb>firstNumb)?firstNumb:nextNumb;
        do
        {
            ostatokChisla=maxNumb%minNumb;
            maxNumb=minNumb;
            minNumb=ostatokChisla;
        }
        while(!ostatokChisla==0);

        printf("%d",maxNumb);
    }



}
