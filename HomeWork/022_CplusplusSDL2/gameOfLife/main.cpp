#include <iostream>
#include <exception>
#include <cstdbool>
#include "sdlwrapper.h"
#include "gamelife.h"

using namespace std;
using namespace function;
int main()
{
    try
    {
        SDLWrapper sdlWrapper;
        SDLWindowWrapper win("Hello RAII!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
        SDLRendererWrapper ren(win.win(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_RenderClear(ren.ren());
        SDL_SetRenderDrawColor(ren.ren(), 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawLine(ren.ren(), 0, 0, 640, 480);
        SDL_RenderPresent(ren.ren());
        int x = 0, y = 0;
        int **array = new int *[SCREENHIGHT / 10];

        for(int i = 0; i < SCREENHIGHT / 10; i++)
            array[i] = new int [SCREENWIDTH / 10];

        for(int i = 0; i < SCREENHIGHT / 10; ++i)
        {
            for(int j = 0; j < SCREENWIDTH / 10; ++j)
            {
                array[i][j] = 0;
            }
        }

        veiw(array, 0, 0, ren.ren());
        control(array, &x, &y, ren.ren());
        logic(array, ren.ren());


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



