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
                printf("|%d|",ttt[i][k][j]);

            }
            printf("\n");
        }
        printf("**level sqr %d**\n",i+1);
    }
}

void playTTTox(int ttt[][SIZE][SIZE],int who)
{

    int tttxZ,tttxY,tttxX;
    do
    {
        printf("pls enter cordinate %c (x,y,z)\nx::",who%2==0?'x':'0');
        scanf("%d",&tttxX);
        printf("y::");
        scanf("%d",&tttxY);
        printf("z::");
        scanf("%d",&tttxZ);
    }
    while(((tttxX>SIZE-1||tttxY>SIZE-1||tttxZ>SIZE-1)&&printf("error cordinate\n"))||((ttt[tttxZ][tttxY][tttxX]==1||ttt[tttxZ][tttxY][tttxX]==2)&&printf("you loxtam uge est %d\n",ttt[tttxZ][tttxY][tttxX])));

    ttt[tttxZ][tttxY][tttxX]=who%2==0?1:2;
}

int vektorTTTox(int ttt[][SIZE][SIZE])
{
    int zg,kg,ig;
    int flags;


    for(int m=0; m<3; m++)//proveriaem 3 ploskosti
    {
        for(int y=0; y<SIZE; y++)
        {
            for(int x=0; x<SIZE; x++)
            {
                for(int vi= -1; vi<2; vi++) //vi,vz,vk eto nashi vektora
                {
                    for(int vz=-1; vz<2; vz++)
                    {
                        for(int vk=-1; vk<2; vk++)
                        {
                            if(m==0)
                            {
                                zg=0;
                                kg=y;
                                ig=x;
                            }
                            if(m==1)
                            {
                                zg=y;
                                kg=x;
                                ig=0;
                            }
                            if(m==2)
                            {
                                zg=x;
                                kg=0;
                                ig=y;
                            }

                            flags=0;

                            if(ttt[zg][kg][ig]!=0)
                            {
                                for(int p=0; p<SIZE&&((zg+vi>=0)&&(kg+vz>=0)&&(ig+vk>=0))&&((zg+vi<SIZE)&&(kg+vz<SIZE)&&(ig+vk<SIZE)); p++,zg+=vi,kg+=vz,ig+=vk)
                                {
                                    if(ttt[zg][kg][ig]==ttt[zg+vi][kg+vz][ig+vk]&&!(vi==0&&vz==0&&vk==0)) flags++;
                                    if(flags==3)return ttt[zg][kg][ig];


                                }
                            }

                        }
                    }
                }
            }
        }
    }

    return 0;
}
