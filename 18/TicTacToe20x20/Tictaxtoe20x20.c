#define SIZE 20
#include <stdio.h>
void tttOxShow(int ticTacMazafak_array[][SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        for(int k=0; k<SIZE; k++)
        {
            printf("|%d|",ticTacMazafak_array[i][k]);
        }
        printf("\n");
    }
}

void playTTTox(int ticTacMazafak_array[][SIZE],int who)
{
    int tttxY,tttxX;
    do
    {
        printf("pls enter cordinate %c (x,y,z)\nx::",who%2==0?'x':'0');
        scanf("%d",&tttxY);
        printf("y::");
        scanf("%d",&tttxX);

    }
    while(((tttxX>SIZE-1||tttxY>SIZE-1)&&printf("error cordinate\n"))||((ticTacMazafak_array[tttxX][tttxY]==1||ticTacMazafak_array[tttxX][tttxY]==2)&&printf("you loxtam uge est %d\n",ticTacMazafak_array[tttxX][tttxY])));

    ticTacMazafak_array[tttxX][tttxY]=who%2==0?1:2;
}

int chekWinGame(int ticTacMazafak_array[][SIZE])
{
    int xx,yy;
    int flags_chek=0;
    for(int k=0; k<SIZE; k++)
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int m=-1; m<2; m++)
            {
                for(int n=-1; n<2; n++)
                {
                    if(ticTacMazafak_array[i][k]!=0)
                    {
                        flags_chek=0;
                        xx=i;
                        yy=k;
                        for(int p=0; p<5&&(xx+m<SIZE&&yy+n<SIZE); p++,xx+=m,yy+=n)
                        {
                            if(ticTacMazafak_array[i][k]==ticTacMazafak_array[xx+m][yy+n]&&!(n==0&&m==0)) flags_chek++;
                            if(flags_chek==4) return ticTacMazafak_array[i][k];
                        }
                    }
                }
            }
        }
    }
    return 0;
}
