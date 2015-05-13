#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <unistd.h>
#include <SDL2/SDL_mixer.h>
int main(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "SDL_Init( Error : %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *win = SDL_CreateWindow("Hello World !", 100, 100, 700, 700, SDL_WINDOW_SHOWN);

    if(win == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow Error : %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(ren == NULL)
    {
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *bmp = SDL_LoadBMP("../media/wtf.bmp");

    if(bmp == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_LoadBMP Error: %s \n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);

    if(tex == NULL)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateTextureFromSurface Error :%s \n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)

        return false;

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    Mix_Music *music = NULL;

    SDL_Event event;
    bool running = false;
    int x = 0, y = 0;
    bool re = true;

    while(!running)
    {
        if(!re)
            exit(0);

        //  execl("finalProject", NULL);

        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)  running = true;

            if(event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&x, &y);


                if((x >= 66) && (x <= 550) && (y >= 638) && (y <= 700))
                {
                    re = true;
                }

                /*first sqr
                x - 66 y - 638         x - 550 y 638
                x - 66 y - 700         x - 550 y - 700
                */
                else if((x >= 550) && (x <= 582) && (y >= 536) && (y <= 800))
                {
                    re = true;
                }

                /*second
                x - 550 y - 536        x 582  y 536
                x - 550 y - 700        x 582  y 700
                */
                else if((x >= 66) && (x <= 550) && (y >= 536) && (y <= 590))
                {
                    re = true;
                }
                /*
                next
                x - 66 y - 536         x - 550 y - 536
                x - 66 y - 590         x - 550 y - 590
                */
                else if((x >= 66) && (x <= 105) && (y >= 300) && (y <= 536))
                {
                    re = true;
                }
                /*
                next
                x - 66 y - 300         x - 105 y - 300
                x - 66 y - 536         x - 105 y - 536
                */
                else if((x >= 105) && (x <= 335) && (y >= 300) && (y <= 342))
                {
                    re = true;
                }
                /*
                next
                x - 105 y - 300        x - 335 y - 300
                x - 105 y - 342        x - 335 y - 342
                */
                else if((x >= 335) && (x <= 354) && (y >= 300) && (y <= 311))
                {
                    re = true;
                }
                /*
                next
                x - 335  y - 300       x - 354 y - 300
                x - 335  y - 311       x - 354 y - 311
                */
                else if((x >= 346) && (x <= 354) && (y >= 237) && (y <= 300))
                {
                    re = true;
                }
                /*
                next
                x - 346 y - 237        x - 354 y - 237
                x - 346 y - 300        x - 354 y - 300
                */
                else if((x >= 322) && (x <= 346) && (y >= 237) && (y <= 243))
                {
                    re = true;
                }
                /*
                next
                x - 322 y - 237        x - 346 y - 237
                x - 322 y - 243        x - 346 y - 243
                */
                else if((x >= 322) && (x <= 330) && (y >= 200) && (y <= 237))
                {
                    re = true;
                }
                /*
                next
                x - 322 y - 200        x - 330 y - 200
                x - 322 y - 237        x - 330 y - 237
                */
                else if((x >= 330) && (x <= 355) && (y >= 200) && (y <= 214))
                {
                    re = true;
                }
                /*
                next
                x - 330 y - 200        x - 355 y - 200
                x - 330 y - 214        x - 355 y - 214
                */
                else if((x >= 346) && (x <= 355) && (y >= 180) && (y <= 200))
                {
                    re = true;
                }
                /*
                next
                x - 346 y - 180        x - 355 y - 180
                x - 346 y - 200        x - 355 y - 200
                */
                else if((x >= 328) && (x <= 370) && (y >= 100) && (y <= 180))
                {

                    music = Mix_LoadMUS("../media/0111.wav");

                    if(music == NULL)
                    {
                        return false;
                    }

                    if(Mix_PlayMusic(music, -1) == -1)
                    {
                        return 1;
                    }
                    bmp = SDL_LoadBMP("../media/nice.bmp");

                    if(bmp == NULL)
                    {
                        SDL_DestroyRenderer(ren);
                        SDL_DestroyWindow(win);
                        fprintf(stderr, "SDL_LoadBMP Error: %s \n", SDL_GetError());
                        SDL_Quit();
                        exit(1);
                    }

                    tex = SDL_CreateTextureFromSurface(ren, bmp);
                    SDL_FreeSurface(bmp);

                    if(tex == NULL)
                    {
                        SDL_DestroyRenderer(ren);
                        SDL_DestroyWindow(win);
                        fprintf(stderr, "SDL_CreateTextureFromSurface Error :%s \n", SDL_GetError());
                        SDL_Quit();
                        exit(1);
                    }

                    //Mix_FreeMusic(music);
                    SDL_RenderClear(ren);
                    SDL_RenderCopy(ren, tex, NULL, NULL);
                    SDL_RenderPresent(ren);
                    SDL_Delay(10000);
                    running = true;

                }
                else re = false;

                /*
                topchik
                x - 328 y - 100        x - 370 y - 100
                x - 328 y - 178        x - 370 y - 178*/

            }

        }
    }




    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}

