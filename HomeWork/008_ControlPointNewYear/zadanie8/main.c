#include <stdio.h>

int main(void)
{
    int userNumb,rez;
    char option;
    do{
        printf("pls enter you first numb = ");
        scanf("%d",&rez);
        option='0';
        while(option!='='&&option!='c'&&option!='e'){
            printf("enter operation    ");
            scanf(" %c",&option);
            if(option!='='&&option!='c'&&option!='e'){
                printf("enter  next numb   ");
                scanf("%d",&userNumb);
                switch(option){
                    case '+': rez+=userNumb;
                    break;
                    case '-': rez-=userNumb;
                    break;
                    case '*': rez*=userNumb;
                    break;
                    case '/': rez/=userNumb;
                    break;
                }
            }
        }
    if(option=='='){
        system("cls");
        printf("your result %d",rez);
        getch();
        system("cls");
    }else system("cls");
   }while(option!='e');
    printf("the end");
    return 0;
}

