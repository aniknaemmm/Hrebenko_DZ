#include "date.h"

int main(void)
{
    Date youDate={1,1,1}, tempDate;
    tempDate=youDate;
     int chois=0;
    printf("Hello,you do not want to work with?\n");
     while (!(chois==7)) {
         printf("\n    menu\n1.Show you first date\n2.Show you next date\n3.adding day\n4.ustonovit' tekushuiu datu dlia otschiota\n"
                "5.enter you date\n6.diff\n7.exit\n");
         scanf("%d",&chois);
         system("clear");
         switch (chois) {
         case 1:
             showDate(youDate);
             break;
         case 2:
             showDate(tempDate);
             break;
         case 3:
             addingDay(&tempDate);
             break;
         case 4:
             youDate=tempDate;
             printf("Well done......100%\n");
             break;
         case 5:
             enterDate(&youDate);
             tempDate=youDate;
             break;
         case 6:
             printf("diff day %d\n",diffDateDay(youDate,tempDate));
             break;
         case 7:
             printf("\the end.\n");
             break;

         default:
             printf("\ninvalid value\n");
             exit(1);
             break;
         }


     }

   return 0;
}
