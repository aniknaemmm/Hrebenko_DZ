#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("Hello world!\n");
    int mass[12][12];
    int first=0,ostr=0,wwrk=0;
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            mass[i][j]=abs(rand()%2);
        }
    }
    for(int i=1; i<11; i++)
    {
        for(int j=1; j<11; j++)
        {
            printf("[%d]",mass[i][j]);
        }
        printf("\n----------------\n");
    }



    for(int i=1; i<11; i++)
    {
        for(int j=1; j<11; j++)
        {
            if(i==1)
            {
                if(mass[i][j]==1&&first==0)
                {
                    first=1;
                    ++ostr;
                    printf("%d %d nomer\n",i,j);
                }
                if(mass[i][j]==0)
                {

                    first=0;
                }
            }




            /*

                        if(mass[i][j]==0||wwrk==1)
                        {
                            if(mass[i][j]==1) first=1;
                            if(mass[i][j]==0&&first==1)
                            {
                                ostr++;
                                first=0;
                            }
                            wwrk=1;
                        }
                        else printf("net ostaravov");*/
        }
    }
    printf("ostrovov %d",ostr);





    return 0;
}
