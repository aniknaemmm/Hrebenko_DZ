#ifndef LISAG_H
#define LISAG_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#define SCREENWIDTH 500
#define SCREENHIGHT 500
#define PI 3.14

void drawLisag(int m,int n,SDL_Renderer *ren);
void control(SDL_Renderer *ren);


#endif // LISAG_H

