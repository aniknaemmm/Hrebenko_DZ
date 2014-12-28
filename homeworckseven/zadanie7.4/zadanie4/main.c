#include <stdio.h>

int main(void)
{ char otvet;
  int n=1;
 do{
      system("cls");
      system("color 2");
      printf("pls enter numb ");
      scanf("%d",&n);
      int factorial=1;
      for(int i=1;i<=n;i++){
           factorial*=i;
        }
      printf("factorial %d!  raven %d\n",n,factorial);
      printf("povtorit'>? y/n\n");
      scanf("%s",&otvet);

  }while(otvet=='y');

  return 0;

  }

