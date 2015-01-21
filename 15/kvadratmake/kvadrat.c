void kvadrat(int razmerKvadrata,int speedAnimation){
  int i,k=1,numb=10;
    while(numb--)
    {
        while(k<razmerKvadrata)
        {
            for(int oopp=0; oopp<speedAnimation;  oopp++)
            {
                for(i=0; i<=k; i++)
                {
                    if(i==0||i==k)
                    {
                        for(int p=0; p<=k; p++)
                        {
                            printf("#");
                            if(p==k) printf("\n");
                        }
                    }
                    else printf("#%*c\n",k,'#');



                }
                system("cls");
            }
            k++;

        }

        while(k!=1)
        {
            for(int oopp=0; oopp<speedAnimation; oopp++)
            {
                for(i=0; i<=k; i++)
                {
                    if(i==0||i==k)
                    {
                        for(int p=0; p<=k; p++)
                        {
                            printf("#");
                            if(p==k) printf("\n");
                        }
                    }
                    else  printf("#%*c\n",k,'#');



                }
                system("cls");
            }
            k--;
        }
    }
}
