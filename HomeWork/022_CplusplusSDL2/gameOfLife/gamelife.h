#ifndef GAMELIFE_H
#define GAMELIFE_H
#include <SDL2/SDL.h>
#define SCREENHIGHT 480
#define SCREENWIDTH 640

namespace function
{
void control(int **array, int *x, int *y, SDL_Renderer *ren);
void veiw(int **array, int x, int y, SDL_Renderer *ren);
void logic(int **array, SDL_Renderer *ren);
void freeMemory(int **array);
}

#endif // GAMELIFE_H

