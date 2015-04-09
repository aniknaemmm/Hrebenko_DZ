#include <iostream>
#include <exception>
#include <cstdbool>
#include "sdlwrapper.h"
#define SCREENHIGHT 480
#define SCREENWIDTH 640
using namespace std;
void control (int **array, int *x, int *y, SDL_Renderer *ren);
void veiw (int **array, int x, int y, SDL_Renderer *ren);
void logic(int **array,SDL_Renderer *ren);
void freeMemory(int **array);
int main()
{
    try
    {
        SDLWrapper sdlWrapper;
        SDLWindowWrapper win("Hello RAII!",100,100,640,480,SDL_WINDOW_SHOWN);
        SDLRendererWrapper ren(win.win(),-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_RenderClear(ren.ren());
        SDL_SetRenderDrawColor(ren.ren(),0xFF,0xFF,0xFF,0xFF);
        SDL_RenderDrawLine(ren.ren(),0,0,640,480);
        SDL_RenderPresent(ren.ren());
        int x=0,y=0;
        int **array=new int *[SCREENHIGHT/10];
        for (int i=0; i<SCREENHIGHT/10; i++)
                    array[i]=new int [SCREENWIDTH/10];

        for (int i=0; i<SCREENHIGHT/10; ++i)
        {
           for (int j=0; j<SCREENWIDTH/10; ++j)
           {
                array[i][j]=0;
           }
        }

        veiw(array,0,0,ren.ren());
        control(array, &x, &y,ren.ren());
        logic(array,ren.ren());


          freeMemory(array);

    }
    catch(exception &e)
    {
        cerr << "error:" << e.what() << endl;
    }
    catch(...)
    {
        cerr << "error : something happ\n";
    }

    cout << "Hello World!" << endl;
    return 0;
}


void control (int **array, int *xPosition, int *yPosition,SDL_Renderer *ren)
{

    int x=*xPosition, y=*yPosition;
    SDL_Event e;
    bool quit =false;
    //veiw(array,x,y,ren);
    while(!quit){
           while (SDL_PollEvent(&e)!=0) {
           //if(e.type == SDL_QUIT)  quit = true;
           if(e.type == SDL_MOUSEBUTTONDOWN)
           {
               SDL_MouseButtonEvent mEvent=e.button;
               array[mEvent.y/10][mEvent.x/10]+=1;
               array[mEvent.y/10][mEvent.x/10]=array[mEvent.y/10][mEvent.x/10]==2?0:1;

           }
           if(e.type == SDL_KEYDOWN)
           {
               SDL_KeyboardEvent kEvent=e.key;
               if(kEvent.keysym.scancode==SDL_SCANCODE_A)
               {
                   x=(x-1+(SCREENWIDTH/10))%(SCREENWIDTH/10);
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_D)
               {
                   x=(x+1)%(SCREENWIDTH/10);
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_W)
               {
                   y=(y-1+SCREENHIGHT/10)%(SCREENHIGHT/10);
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_S)
               {
                   y=(y+1)%(SCREENHIGHT/10);
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_K)
               {
                    x=0;
                    y=0;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_SPACE)
               {
                   array[y][x]+=1;
                   array[y][x]=array[y][x]==2?0:1;
               }
               if(kEvent.keysym.scancode==SDL_SCANCODE_C)
                    quit=true;
         }
         veiw(array,x,y,ren);
      }
   }
}

void veiw (int **array, int x, int y, SDL_Renderer *ren)
{
    SDL_Rect squr;
        squr.h=10;
        squr.w=10;
        SDL_SetRenderDrawColor(ren,0x00,0x00,0x00,0xFF);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren,0x00,0xFF,0x00,0xFF);
        for (int i=0; i<SCREENHIGHT/10; ++i)
        {
            for (int j=0; j<SCREENWIDTH/10; ++j)
            {
                if(array[i][j]==1)
                {
                    squr.y=i*10;
                    squr.x=j*10;

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

void logic(int **array,SDL_Renderer *ren){

    int **arrayTemp=new int  *[SCREENHIGHT/10];
    for (int i=0; i<SCREENHIGHT/10; i++)
                arrayTemp[i]= new int [SCREENWIDTH/10];

    for (int i=0; i<SCREENHIGHT/10; ++i)
    {
        for (int j=0; j<SCREENWIDTH/10; ++j)
        {
            arrayTemp[i][j]=0;
        }
    }


    int screenWidth=SCREENWIDTH/10;
    int screenHight=SCREENHIGHT/10;
    int chekosition=0;
    int speed=500; //speed animation
    SDL_Event e;
    bool quit=false;
    while(!quit){
         while (SDL_PollEvent(&e)!=0) {
            if(e.type == SDL_QUIT)  quit = true;
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_MouseButtonEvent mEvent=e.button;
                array[mEvent.y/10][mEvent.x/10]+=1;
                array[mEvent.y/10][mEvent.x/10]=array[mEvent.y/10][mEvent.x/10]==2?0:1;
                veiw(array,screenWidth+1,0,ren);
            }
            if(e.type == SDL_KEYDOWN){
            SDL_KeyboardEvent kEvent=e.key;
            if(kEvent.keysym.scancode==SDL_SCANCODE_A)
            {
                if(speed!=0)
                speed-=50;
            }
            if(kEvent.keysym.scancode==SDL_SCANCODE_S)
            {
                if(speed!=500)
                    speed+=50;
            }

            }
         }
    for (int i=0; i<SCREENHIGHT/10; ++i)
    {
        for (int j=0; j<SCREENWIDTH/10; ++j)
        {
            for (int vi=-1; vi<2; ++vi)
            {
                for (int vj=-1; vj<2; ++vj)
                {
                  if(array[(i+vi+screenHight)%screenHight][(j+vj+screenWidth)%screenWidth]==1&&!(vi==0&&vj==0))
                  {
                      chekosition++;
                  }

                }
            }
            if(array[i][j]==1){
                if((chekosition==2||chekosition==3))
                {
                    arrayTemp[i][j]=1;
                }
                else
                {
                    arrayTemp[i][j]=0;
                }
            }
            else
            {
                if(chekosition==3)
                {
                    arrayTemp[i][j]=1;
                }
                else arrayTemp[i][j]=0;
            }
            chekosition=0;
        }
    }

    for (int i=0; i<SCREENHIGHT/10; ++i)
    {
        for (int j=0; j<SCREENWIDTH/10; ++j)
        {
            array[i][j]=arrayTemp[i][j];
        }
    }
    SDL_Delay(speed);
    veiw(array,screenWidth+1,0,ren);
   }
    freeMemory(arrayTemp);
}

void freeMemory(int **array){
    for(int i=0;i<SCREENHIGHT/10;i++)
    {
        delete [] array[i];
    }

}

