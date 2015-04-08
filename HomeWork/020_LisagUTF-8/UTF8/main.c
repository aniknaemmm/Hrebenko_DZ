#include <stdio.h>
#include <string.h>
int main(void)
{
    int tempstring;
    char *string="АаБбВв!";
    int res=strlen(string);
    int codepoint=0;
    for(int i=0;i<res;++i){
        if((string[i]&0x80)==0)
        codepoint++;
        tempstring=string[i];

            codepoint++;
        //if((string[i]&0xE0)==0xC0)




    }
    printf("Hello World!\n%d",codepoint);
    return 0;
}

