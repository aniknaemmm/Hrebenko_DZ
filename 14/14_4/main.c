#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/kvadrat.h"
int main()
{ int razmerKvadrata,speedAnimation;
  printf("hello wrd");
printf("pls enter razmer kv(1<)\n");
scanf("%d",&razmerKvadrata);
printf("pls enter spead animation(0<)\n");
scanf("%d",&speedAnimation);
kvadrat(razmerKvadrata,speedAnimation);
    return 0;
}
