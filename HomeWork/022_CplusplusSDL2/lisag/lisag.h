#ifndef LISAG_H
#define LISAG_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#define SCREENWIDTH 700
#define SCREENHIGHT 700
#define PI 3.14

namespace fun{
void drawLisag(int m,int n,SDL_Renderer *ren);
void control(SDL_Renderer *ren);
}

#endif // LISAG_H

