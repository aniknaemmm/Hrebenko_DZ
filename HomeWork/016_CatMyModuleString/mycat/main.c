/* Программа счета в обратном порядке. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[10];
    int disp, count;
    gets(str);
    printf(str);
   /* switch(argc)
    {

    case 1:
        while(1)
        {
            fscanf(str);
            fprintf(stdout,"%s\n",str);
        }

        break;

    case 2


    }
      if(argc<2) {
        printf("В командной строке необходимо ввести число,с которого\n");
        printf("начинается отсчет.  Попробуйте снова.\n");
        exit(1);
      }

      if(argc==3 && !strcmp(argv[2], "display")) disp = 1;
      else disp = 0;

      for(count=atoi(argv[1]); count; --count)
        if(disp) printf("%d\n", count);

      putchar('\a');   здесь подается звуковой сигнал
      printf("Счет закончен");
    */
    return 0;
}
