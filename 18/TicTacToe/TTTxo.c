#include <stdio.h>
#define SIZE 4
void tttOxShow(int ttt[][SIZE][SIZE])
{

    for(int i=0; i<SIZE; i++)
    {
        for(int k=0; k<SIZE; k++)
        {
            for(int j=0; j<SIZE; j++)
            {
                printf("%d",ttt[i][k][j]);

            }
            printf("\n");
        }
        printf("\n");
    }
}

void playTTTox(int ttt[][SIZE][SIZE]){

    int tttxX,tttxY,tttxZ,tttoX,tttoY,tttoZ;
    do{
    printf("pls enter cordinate X (x,y,z)");
    scanf("%d%d%d",&tttxX,&tttxY,&tttxZ);

    }while(((tttxX>SIZE-1||tttxY>SIZE-1||tttxZ>SIZE-1)&&printf("error\n"))||((ttt[tttxZ][tttxY][tttxX]==1)&&printf("you lox")));


   do{
printf("pls enter cordinate O (x,y,z)");
    scanf("%d%d%d",&tttoX,&tttoY,&tttoZ);
   }while((tttoX>SIZE-1||tttoY>SIZE-1||tttoZ>SIZE-1)&&printf("error\n"));

ttt[tttxZ][tttxY][tttxX]=1;
ttt[tttoZ][tttoY][tttoX]=2;

}
