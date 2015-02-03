#include <string.h>
#include <stdio.h>
#include <math.h>



int main()
{

	char mas[]="+.>.+.";
	char arr[30000];
	for(int i=0;i<30000;i++)arr[i]=' ';
	int k=0;

	for(int i=0;i<strlen(mas);i++)
	{

		switch(mas[i])
		{
		case '!':arr[k]=' ';break;
		case '>':k++;break;
		case '<':k--;break;
		case '+':arr[k]++;break;
		case '-':arr[k]--;break;
	    case '.': putchar(arr[k]);break;

		}

	}
	return 0;
}
