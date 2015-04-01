/*#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <math.h>
int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        fprintf(stderr,"SDL_Init( Error : %s\n",SDL_GetError());
        exit(1);
    }
    SDL_Window *win = SDL_CreateWindow("Hello World !",100,100,640,480,SDL_WINDOW_SHOWN);
    if(win==NULL){
        fprintf(stderr,"SDL_CreateWindow Error : %s\n",SDL_GetError());
        exit(1);
    }


     if(IMG_Init(IMG_INIT_PNG)==0){
         SDL_DestroyWindow(win);
         fprintf(stderr,"SDL_Init( Error : %s\n",IMG_GetError());
         IMG_Quit();
         SDL_Quit();
         exit(1);
     }




    SDL_Renderer *ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(ren == NULL){
        SDL_DestroyWindow(win);
        fprintf(stderr,"SDL_CreateRenderer Error: %s\n",SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    SDL_Surface *bmp = IMG_Load("../res/image.png");

    if(bmp==NULL){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr,"SDL_LoadBMP Error: %s \n",SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Texture *tex =SDL_CreateTextureFromSurface(ren,bmp);
    SDL_FreeSurface(bmp);
    if(tex ==NULL){

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr,"SDL_CreateTextureFromSurface Error :%s \n",SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    SDL_SetRenderDrawColor(ren,0x00,0xFF,0x00,0xFF);
    SDL_RenderClear(ren);
    int x,y,t=0;
    while(1){
    for(int i=0;i<12;i++){
        x=128*cos((3.14*i/6)+t);
        y=128*sin((3.14*i/6)+t);
        SDL_Rect dest={x+288,y+208,64,64};

        SDL_RenderCopy(ren,tex,NULL,&dest);
    }
    SDL_RenderPresent(ren);
    SDL_RenderClear(ren);
    SDL_Delay(10);
    t++;
}


    SDL_RenderPresent(ren);
    SDL_Delay(40000);

    IMG_Quit();
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

     return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdbool.h>
int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        fprintf(stderr,"SDL_Init( Error : %s\n",SDL_GetError());
        exit(1);
    }
    SDL_Window *win = SDL_CreateWindow("Hello World !",100,100,640,480,SDL_WINDOW_SHOWN);
    if(win==NULL){
        fprintf(stderr,"SDL_CreateWindow Error : %s\n",SDL_GetError());
        exit(1);
    }


     if(IMG_Init(IMG_INIT_PNG)==0){
         SDL_DestroyWindow(win);
         fprintf(stderr,"SDL_Init( Error : %s\n",IMG_GetError());
         IMG_Quit();
         SDL_Quit();
         exit(1);
     }




    SDL_Renderer *ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(ren == NULL){
        SDL_DestroyWindow(win);
        fprintf(stderr,"SDL_CreateRenderer Error: %s\n",SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    SDL_Surface *bmp = IMG_Load("../res/image2.png");

    if(bmp==NULL){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr,"SDL_LoadBMP Error: %s \n",SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Texture *tex =SDL_CreateTextureFromSurface(ren,bmp);
    SDL_FreeSurface(bmp);
    if(tex ==NULL){

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr,"SDL_CreateTextureFromSurface Error :%s \n",SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    SDL_SetRenderDrawColor(ren,0x00,0xFF,0x00,0xFF);
    SDL_RenderClear(ren);




int x=0,y=0,t=0;

    SDL_Event e;
    bool quit=false;
    while(!quit){
        Uint32 ticks=SDL_GetTicks();
        Uint32 sprite=(ticks/100)%7;
       SDL_PollEvent(&e);
        //SDL_WaitEvent(&e);
        switch (e.type) {
        case SDL_QUIT:
            quit=true;
            break;


}
       // for(int i=0;i<4;i++){
          //  x=128*cos((3.14*i/6)+t);
           // y=128*sin((3.14*i/6)+t);
            SDL_Rect dest={x+200,y+200,128,256};
            SDL_Rect src={(sprite%4)*128,0,128,256};
            SDL_RenderCopy(ren,tex,&src,&dest);


    //}
            //t++;
        SDL_RenderPresent(ren);
          SDL_RenderClear(ren);


    }





    IMG_Quit();
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

     return 0;
}


