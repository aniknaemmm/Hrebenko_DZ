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
	for(int i=0;i<30000;i++)arr[i]=0;
		int k=0;

	for(int i=0;i<strlen(mas)&&end==0;i++)
	{

		switch(mas[i])
		{
		case '>':k++;break;
		case '<':k--;break;
		case '+':arr[k]++;break;
		case '-':arr[k]--;break;
	    case '.':putchar(arr[k]);break;
	    case ',':arr[k]=getchar();
        case ';':end =1;
        case '[':
            stack
            if(arr[k]!=0)k++;
            else
		}

	}
	return 0;
}
