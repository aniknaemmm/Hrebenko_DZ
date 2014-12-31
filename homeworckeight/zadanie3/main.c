#include <stdio.h>
#include <stdlib.h>

int main()
{

    int userNumb;
    int seredinaElki;
    int visotaElki=2;
    printf("hello user\n pls enter number tiers  ");
    scanf("%d",&userNumb);
    system("cls");
    system("color 2");//new year style
    seredinaElki=userNumb;

    for(int kollRombikov=0;kollRombikov<userNumb;kollRombikov++){
       int ser=seredinaElki;
       for(int p=0;p<visotaElki;p++){
           for(int k=0;k<ser;k++){
                printf(" ");
           }
           ser--;
           if(p!=visotaElki-1){
           for(int m=0;m<=2*p;m++){
              if((m==0||m==2*p)) printf("*");
              else printf(" ");
           }
           }else{
                for(int m=0;m<=2*p;m++){
                    printf("#");
                }

           }
           printf("\n");

         }
       visotaElki++;
       }
if(userNumb>=3){
    for(int m=0;m<userNumb-2;m++){
        printf("\n");
        for(int v=0;v<userNumb-1;v++){
             printf(" ");
         }
        for(int y=0;y<3;y++){
            if(y==0||y==2) printf("#");
            else printf(" ");
        }
   }
}else{
    for(int v=0;v<userNumb;v++){
        printf(" ");
    }
    printf("#");
}
    return 0;
}

