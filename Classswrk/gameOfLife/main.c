#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#define SCREENWIDTH 640
#define SCREENHIGHT 480

void control (int **arrey, int *a, int *s);
void veiw (int **arrey, int x, int y, SDL_Renderer *ren);

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

    int x=0,y=0;
    int **arrey=NULL;
    arrey=(int**)malloc(SCREENHIGHT/10 *sizeof(int*));
    for (int i=0; i<SCREENHIGHT/10; i++)
    {
        arrey[i]=malloc(SCREENWIDTH/10 *sizeof(int));
    }
    for (int i=0; i<7; i++)
    {
        control(arrey, &x, &y);
        veiw(arrey, x, y, ren);
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

     return 0;
}

void control (int **arrey, int *a, int *s)
{

    int x=*a, y=*s;
    SDL_Event e;
    bool quit =false;

    while(SDL_WaitEvent (&e)==0)
    {
        while (SDL_PollEvent(&e)!=0) {
           if(e.type == SDL_QUIT)  quit = true;
           if(e.type == SDL_KEYDOWN){
               SDL_KeyboardEvent kEvent=e.key;
               //if(kEvent.keysym.scancode==SDL_SCANCODE_A) printf("A\n");
               if(kEvent.keysym.scancode==SDL_SCANCODE_A){
                   x=(x-10+SCREENWIDTH)%SCREENWIDTH;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_D){
                   x=(x+10+SCREENWIDTH)%SCREENWIDTH;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_W){
                   y=(y-10+SCREENHIGHT)%SCREENHIGHT;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_S){
                   y=(y+10+SCREENHIGHT)%SCREENHIGHT;
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_K){
                    x=0;
                    y=0;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_SPACE){

                    if (arrey[x/10][y/10]==1)
                   arrey[x/10][y/10]=0;
                    if (arrey[x/10][y/10]==0)
                   arrey[x/10][y/10]=1;
               }


           }
        }

    }

}

void veiw (int **arrey, int x, int y, SDL_Renderer *ren)
{
    SDL_Rect squr;
        squr.h=10;
        squr.w=10;


        for (int i=0; i<SCREENHIGHT/10; ++i)
        {
            for (int j=0; j<SCREENWIDTH/10; ++j)
            {
                if(arrey[i][j]==1)
                {
                    squr.y=j*10;
                    squr.x=i*10;
                    SDL_SetRenderDrawColor(ren,0x00,0xFF,0x00,0xFF);
                    SDL_RenderFillRect(ren, &squr);
                }
            }
        }
        squr.y=y;
        squr.x=x;



        SDL_SetRenderDrawColor(ren,0x00,0x00,0x00,0xFF);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren,0xFF,0x00,0x00,0xFF);
        SDL_RenderFillRect(ren, &squr);
        SDL_RenderPresent(ren);
}
