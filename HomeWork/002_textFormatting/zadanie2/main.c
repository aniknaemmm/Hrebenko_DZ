#include <stdio.h>
#include <stdlib.h>

int main()
{
char ma[]="mama";
char my[]="myla";
char ra[]="ramy";
printf("%s %s %s\n",ma,my,ra);
printf("%s %s %s\n",ma,ra,my);
printf("%s %s %s\n",my,ma,ra);
printf("%s %s %s\n",my,ra,ma);
printf("%s %s %s\n",ra,my,ma);
printf("%s %s %s\n",ra,ma,my);
    return 0;
}
