#include <stdio.h>

int main(void)
{
    int n,m;
    printf("hello user\n pls enter n=");
    scanf("%d",&n);
    printf("okey...\n pls enter  m=");
    scanf("%d",&m);
        system("cls");

    for(int i=1;i<=n;i++){
        for(int p=1;p<=m;p++){
            if(i%2!=0){
                if(p%2==0) printf("#");
                else printf(" ");
            }else {
                if(p%2!=0) printf("#");
               else  printf(" ");
            }


        }
        printf("\n");
    }


    return 0;
}

