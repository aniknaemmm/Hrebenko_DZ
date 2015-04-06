#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/perevod.h"
int main()
{
    int userNumb, osnovanieSystem;
    printf("Pleas enter you number and sysnumb(2-36):");
    scanf("%d%d",&userNumb,&osnovanieSystem);
    printf("You number v sysnumb %d result :",osnovanieSystem);
    function(userNumb,osnovanieSystem);
    return 0;
}
