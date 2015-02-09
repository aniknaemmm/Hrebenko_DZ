#include <string.h>
#include <stdio.h>
#include <math.h>



int main()
{
    char mas[30000];
    char arr[30000];
    char stack[30000];
    int addresBrak[30000];
    scanf("%s",&mas);
    int end=0;
    for(int i=0; i<30000; i++)arr[i]=0;
    int k=0;

    for(int i=0; i<strlen(mas); i++)
    {
    //printf("%  d-W%d  ",arr[0],arr[1]);
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
