#include <iostream>
#include <exception>
#include "sdlwrapper.h"
#include "lisag.h"
#define _POSIX_C_SOURCE 200112L
#define ALSA_PCM_NEW_HW_PARAMS_API
#include <alsa/asoundlib.h>
#include <alloca.h>
#include <unistd.h>

using namespace std;
using namespace fun;
int main()
{
    try
    {
        SDLWrapper sdlWrapper;
        SDLWindowWrapper win("Hello RAII!",100,100,SCREENWIDTH,SCREENHIGHT,SDL_WINDOW_SHOWN);
        SDLRendererWrapper ren(win.win(),-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_RenderClear(ren.ren());
        control(ren.ren());
    }
    catch(exception &e)
    {
        cerr << "error:" << e.what() << endl;
    }
    catch(...)
    {
        cerr << "error : something happ\n";
    }

    return 0;
}

