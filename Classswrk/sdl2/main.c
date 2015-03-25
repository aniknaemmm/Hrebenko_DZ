#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#define SCREENWIDTH 1280
#define SCREENHIGHT 1024
int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        fprintf(stderr,"SDL_Init( Error : %s\n",SDL_GetError());
        exit(1);
    }
    SDL_Window *win = SDL_CreateWindow("Hello World !",100,100,1280,1024,SDL_WINDOWEVENT_SHOWN);
    if(win==NULL){
        fprintf(stderr,"SDL_CreateWindow Error : %s\n",SDL_GetError());
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(ren == NULL){
        SDL_DestroyWindow(win);
        fprintf(stderr,"SDL_CreateRenderer Error: %s\n",SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    SDL_Surface *bmp = SDL_LoadBMP("../res/hello.bmp");

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

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,tex,NULL,NULL);

    bool quit =false;
    SDL_Event e;

    int x=10,y=10;
    int t=0; //vremia
    while(!quit){
        while (SDL_PollEvent(&e)!=0) {
           if(e.type == SDL_QUIT)  quit = true;
           if(e.type == SDL_KEYDOWN){
               SDL_KeyboardEvent kEvent=e.key;
               //if(kEvent.keysym.scancode==SDL_SCANCODE_A) printf("A\n");
               if(kEvent.keysym.scancode==SDL_SCANCODE_A){
                   x=(x-5+SCREENWIDTH)%SCREENWIDTH;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_D){
                   x=(x+5+SCREENWIDTH)%SCREENWIDTH;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_W){
                   y=(y-5+SCREENHIGHT)%SCREENHIGHT;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_S){
                   y=(y+5+SCREENHIGHT)%SCREENHIGHT;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_K){

               }

           }
           if(e.type == SDL_MOUSEBUTTONDOWN) quit =true;


        }

        x=cos(3.1415/2+0.5*sin(10*3.1415*t/180))*SCREENHIGHT/3+SCREENWIDTH/2;
        y=sin(3.1415/2+0.5*sin(11*3.1415*t/180))*SCREENHIGHT/3+SCREENHIGHT/2;

        SDL_SetRenderDrawColor(ren,0x00,0x00,0x00,0xFF);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderDrawLine(ren,x,y,SCREENWIDTH/2,SCREENHIGHT/2);// or Point
        aacircleRGBA(ren,x,y,20,0xFF,0x7F,0x00,0xFF);
        SDL_RenderPresent(ren);
        ++t;
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

     return 0;
}

