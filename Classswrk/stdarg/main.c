#include <stdio.h>
#include <stdarg.h>
int findMax(int n, ...);
int main(void)
{

    printf("Hello World!%d\n",findMax(5,-1,2,3,-2,4));
    return 0;
}

int findMax(int n, ...)
{
    int max;
    va_list theList;
    va_start(theList, n);
    max = va_arg(theList, int);
    for(int i = 1; i < n; ++i)
    {
        int val = va_arg(theList,int);
        max = max > val ? max : val;
    }

    va_end(theList);
    return max;
}
