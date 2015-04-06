#include "lisag.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        fprintf(stderr,"SDL_Init( Error : %s\n",SDL_GetError());
        exit(1);
    }
    SDL_Window *win = SDL_CreateWindow("Hello World !",100,100,SCREENWIDTH,SCREENHIGHT,SDL_WINDOW_SHOWN);
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

    SDL_RenderClear(ren);
    control(ren);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

     return 0;
}

