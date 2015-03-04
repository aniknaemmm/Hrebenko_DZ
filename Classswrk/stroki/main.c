/*'\0'- ноль
0x0 -ноль //конец строки

объявление строки
char str[5]="mama";

делаем глюки >_>*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>// работа со строками
//сайты cppreference and cplusplus.com
/*int main()
{
    long long int a=0xFEFEFEFEFEFEFEFE;
    char str[8]="mamarama"; //можно поменять на 9 и всё ок
    long long int b=0xDADADADADADADADA;
    printf("%s\n",str);
    for(char *p=str;*p;p++) printf("%c\t%#x\n",*p,*p);

    return 0;
}*/

//баг 2 (для начала всё ок)
/*
int main()
{
    char str1[5]="mama";
    char *str2="mama";
    printf("%s\n%s\n",str1,str2);//normal;
    str2[0]='r';//str2  в памяти литералов нельзя менять; str1  в стеке;
    printf("%s\n%s\n",str1,str2);//raz

    return 0;
}*/
/*
 дома strcpg(char *dost,const char *source);
      strcat(--//--,--//--);
      strcmp(const char *a,const char *b);
char *strchr(const char* hasstac,char reedle);
char *strstr(const char *hasstac,shar *reedles);
char *strtok(const char *str,const char *delimeter);

-------------------параметры коммандной строки
дома написать кэт домашний вариант
int main(int argc,char **argv)
{
    char *a="--help";
    for(int i=0; i<argc; ++i)
    {
         printf("%s\n",argv[i]);

        if(strcmp(a,argv[i])==0) printf ("helper\n");
    }

    return 0;
}*/
/*
FILE *file;
file=fopen("имя файла",строка с режимом открытия "r");
r - открытие файла на чтение (если нет то возврощает NULL);
w - открытие на запись
а - добовление
 можно добавить + тогда добовяються опции
b - открытие в бинарном режиме
fclose(file); закрытие файла
        freopen("zuzu.txt","r",stdin);
        fprintf(file,"%d\n",15);
        fscanf();
        sscanf();
        sprintf();
        (пример
         char str[256];
         sprintf(str,"sleep%f",1.5);
         printf("%s\n",str)
         )
