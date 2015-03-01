#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
    int a=0;
    char mas[30000];
    char arr[30000]= {0};
    int addresBrak[30000];
    for(int m=0; m<30000; m++)arr[m]='0';
    do
    {
        mas[a]=getchar();

    }
    while(mas[a++]!='\n');
    int end=0,k=0;

    for(int i=0; i<a; i++)
    {
        switch(mas[i])
        {
        case '>':
            k++;
            break;
        case '<':
            k--;
            break;
        case '+':
            arr[k]++;
            break;
        case '-':
            arr[k]--;
            break;
        case '.':
            putchar(arr[k]);
            break;
        case ',':
            arr[k]=getchar();
        case ';':
            return 0;
        case '[':
            if (arr[k]==0)
                while (mas[i]!=']')
                    i++;
            else
            {
                addresBrak[end++]=i;

            }

            break;
        case ']':
            if(end==0) return 1;
            if (arr[k]!=0)
                i=addresBrak[end-1];
            else
            {

                end--;
            }
            break;

        }

    }


    return 0;
}
