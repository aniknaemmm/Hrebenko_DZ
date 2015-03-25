#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

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
    SDL_RenderPresent(ren);
    SDL_Delay(4000);

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

     return 0;
}

