#include "lisag.h"

void fun::drawLisag(int m,int n,SDL_Renderer *ren)
{
    int x,y;
    SDL_SetRenderDrawColor(ren,0x00,0x00,0x00,0xFF);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren,0xFF,0xFF,0xFF,0xFF);
    for(double i=0;i<2*PI;i+=0.001)
    {
        x=SCREENWIDTH/2+350*sin((m*i));
        y=SCREENWIDTH/2+350*cos((n*i));

        SDL_RenderDrawPoint(ren,x,y);// or Point
    }
     SDL_RenderPresent(ren);
}

void fun::control(SDL_Renderer *ren)
{
    bool quit =false;
    SDL_Event e;

    int m=1,n=1;
    fun::drawLisag(m,n,ren);
    while(!quit){
        while (SDL_PollEvent(&e)!=0) {
            if(e.type == SDL_QUIT)  quit = true;
            if(e.type == SDL_KEYDOWN){
                SDL_KeyboardEvent kEvent=e.key;
                if(kEvent.keysym.scancode==SDL_SCANCODE_A)
                {
                    m+=1;
                }
                if(kEvent.keysym.scancode==SDL_SCANCODE_D)
                {
                    if(m>0) m-=1;
                }
                if(kEvent.keysym.scancode==SDL_SCANCODE_W)
                {
                    n++;
                }
                if(kEvent.keysym.scancode==SDL_SCANCODE_S)
                {
                    if(n>0) n--;
                }
                drawLisag(m,n,ren);
           }
           if(e.type == SDL_MOUSEBUTTONDOWN) quit =true;
      }
   }
}
