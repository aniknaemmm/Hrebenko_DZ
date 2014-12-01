#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14565757577
int main()
{
   // форматирование ввода и вывода
   //formatirovanie vvoda i vvivoda
   //vvoditcz massiv do probela modifikator %s
  // char name[40];
    //char name2[40];
   //scanf("%s%s",name,name2);
   //printf("%s%s\n",name,name2);
   //ispol'zovanie strlen and sizeof
  //    printf("%d-----%d\n",strlen(name),sizeof(name));
   // vivod const
   //   printf("%.3f",PI);
//------------------------------------------------------------
// chto znaachit %a and %A?
// %c vozvroshaet 1 simvol
// %d vozroshet chislo 10-e


    char x='T';
    int a=234;
    int f=-234;
    float c=2314.23;
    double d=3.54e+32;
    int vos=07342;
    unsigned int k =234;
    int fa=0x1E3;
    printf("Modificator %%a and %%A xz chto vozroshaet double x=3.1e32; otvet:%a\n",d);
    printf("Modificator %%c  vozroshaet odinochniy simvol cahar x ='T'; otvet : %c\n",x);
    printf("Modificator %%d  vozroshaet des9tishnoe chislo int a =234; otvet : %d\n",a);
    printf("Modificator %%e and %%E  vozroshaet exp foru double d =3.54e+32; otvet : %.2e and %.2E\n",d,d);
    printf("Modificator %%f  vozroshaet des9tishnoe s plav zap9toi chislo float a =2314.23; otvet : %.2f\n",c);
    printf("Modificator %%i  vozroshaet des9tishnoe chislo so znakom int f = -234; otvet : %i\n",f);
    printf("Modificator %%o  vozroshaet vosm9richn chislo int vos=07342; otvet : %o\n",vos);
    printf("Modificator %%s  vozroshaet des9tishnoe chislo int a =234; otvet : kak zadat' stoku?\n");
    printf("Modificator %%u  vozroshaet des9tishnoe chislo bez znakom int f = -234; otvet : %u\n",k);
    printf("Modificator %%x  vozroshaet 16-ti richnoe chislo  int fa = 0x1E3; otvet : %x\n",fa);
    printf(" %% pechatoet's9 s pomoshiu %%%%");


  //    printf("%a",d);


   return 0;
}
