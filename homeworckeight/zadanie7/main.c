#include <stdlib.h>
#include <stdio.h>
int main(void){
    int numbOne,numbTwo,numbTt;
    printf("vasha mama poprosila vas sxodit vas za xlebom");
    printf("i tut vi poshli v magaz");
    printf("i kogda vi prishli v magaz chto ze vz9t'\n");
    printf("1. xleb\n"
           "2. snikers\n"
           "3. piva\n"
           "4. nishego ne vz9t' ostavit' dengi sebe\n");
    scanf("%d",&numbOne);
    system("cls");
    if(numbOne==4) printf("skazat' chto tebia ograbili i poiti spat'");
    if(numbOne==1||numbOne==2){
        printf("im: -mama ia prinios %s\n", numbOne==1?"xleba":"snikers");
        printf("%s", numbOne==1?"mama -spasibo za eto":"mama -zachem snikers to vzi9l>?\n");
        if(numbOne==1){
            printf("teper ti mogesh pogul9t'\n"
                              "1. comp\n"
                              "2. ulica\n"
                              "3. pospat\n");
             scanf("%d",&numbTwo);
             system("cls");
             switch(numbTwo){
                 case 1: printf("poigrais9 za compom i idi pospi");
                 break;
                 case 2: printf("poigrais9 na ulke i idi pospi");
                 break;
                 case 3: printf("pospi i potom esho pospi");
                 break;
                 default: printf("idi pospi \a ti slihkom ustal");
             }
        }
        if(numbOne==2){
            printf("ax ti pi*duk uxodi iz ddoma i bez xleba ne prixodi'\n"
                              "1. poiti ukrast' xleb\n"
                              "2. poiti zarabotat' na xleb\n"
                              "3. pospat\n");
             scanf("%d",&numbTt);
             system("cls");
             switch(numbTt){
                 case 1: printf("tut vso ochen' slogno idi pospi");
                 break;
                 case 2: printf("pochti chto toge samoe chto ukrast' no slognee poetomu idi pospi");
                 break;
                 case 3: printf("pospi i potom esho pospi");
                 break;
                 default: printf("idi pospi \a ti slihkom ustal");
             }
        }
   }
    if(numbOne==3){
        int pivo=3;
        int puzo=0;
        while((pivo>0)&&(puzo<4)){
            system("cls");
            printf("popit' piva>/?\n"
               "0. ne pit\n"
               "1. popit'\n");
            scanf("%d",&pivo);
            puzo++;
            if(puzo==4){
                system("cls");
                printf("perepil\n");
                getch();
            }
        }
        system("cls");
        system("pause");
        system("cls");
        int provNaP9ianost;
        printf("proverka na pia9nost' 2+2=");
        scanf("%d",&provNaP9ianost);
        if(provNaP9ianost==4){
            printf("ti trezv idi pospi =)");
        }
        else {
             if(puzo==1) printf("ti gdeto doetogo uge xriapnul!!\n");
             printf("ti pian idi pospi");
        }
    }
    getch();
    system("cls");
    int pospal;
    printf("ti pospal>?\n"
           "1. pospal\n"
           "2. ne pospal\n");
    scanf("%d",&pospal);
    if(pospal==1) printf("mlodec idi pospi esho");
    else   system("shutdown.exe /p"); ///and /r -reboot /p vikl /l bistr vikl

    return 0;
}



