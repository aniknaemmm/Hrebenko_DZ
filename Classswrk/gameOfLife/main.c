#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#define SCREENWIDTH 640
#define SCREENHIGHT 480

void control (int **array, int *xPosition, int *yPosition,SDL_Renderer *ren);
void veiw (int **array, int x, int y, SDL_Renderer *ren);

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
    int **array=NULL;
    array=(int**)malloc(SCREENHIGHT/10 *sizeof(int*));
    for (int i=0; i<SCREENHIGHT/10; i++)
        array[i]=(int *)malloc(SCREENWIDTH/10 *sizeof(int));
    for (int i=0; i<SCREENHIGHT/10; ++i)
    {
        for (int j=0; j<SCREENWIDTH/10; ++j)
           array[i][j]=0;
    }



        control(array, &x, &y,ren);



    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

     return 0;
}

void control (int **array, int *xPosition, int *yPosition,SDL_Renderer *ren)
{

    int x=*xPosition, y=*yPosition;
    SDL_Event e;
    bool quit =false;

    while(!quit)
    {
        while (SDL_PollEvent(&e)!=0) {
           if(e.type == SDL_QUIT)  quit = true;
           if(e.type == SDL_KEYDOWN){
               SDL_KeyboardEvent kEvent=e.key;
               //if(kEvent.keysym.scancode==SDL_SCANCODE_A) printf("A\n");
               if(kEvent.keysym.scancode==SDL_SCANCODE_A){
                   x=((x-1+SCREENWIDTH)/10)%(SCREENWIDTH/10);
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_D){
                   x=(x+1)%(SCREENWIDTH/10);
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_W){
                   y=(y-1+SCREENHIGHT/10)%(SCREENHIGHT/10);
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_S){
                   y=(y+1)%(SCREENHIGHT/10);
                   //--x;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_K){
                    x=0;
                    y=0;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_SPACE){

                    if (array[y][x]==1)
                   array[y][x]=0;
                    if (array[y][x]==0)
                   array[y][x]=1;
               }

           }
        }
        veiw(array, x, y, ren);


    }

}

void veiw (int **array, int x, int y, SDL_Renderer *ren)
{
   SDL_Rect squr;
   squr.h=10;
   squr.w=10;

   SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
   SDL_RenderClear(ren);
        for (int i=0; i<SCREENHIGHT/10; ++i)
        {
            for (int j=0; j<SCREENWIDTH/10; ++j)
            {
                if(array[i][j]==1)
                {
                    squr.y=i*10;
                    squr.x=j*10;
                    SDL_SetRenderDrawColor(ren,0x00,0xFF,0x00,0xFF);
                    SDL_RenderFillRect(ren, &squr);
                }
            }
        }
       squr.y=y*10;
       squr.x=x*10;

        SDL_SetRenderDrawColor(ren,0xFF,0x00,0x00,0xFF);
        SDL_RenderFillRect(ren, &squr);
        SDL_RenderPresent(ren);
}


