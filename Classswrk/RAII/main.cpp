#include <iostream>
#include <exception>
#include "sdlwrapper.h"
using namespace std;

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
        SDL_Delay(5000);
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

//RAII
/*
 * при создании ресураса он инициализируеться а после того как ненужен деинициализируеться
 * RAII  основоно на конструкторах и диструкторах
 * конструктор специальный метод который вызываеться при создание обьекта и вызываеться его при инициализации
 * конструктор должен называться
 * метод ничего не возаврощает
 * конструктор получает либо 0 либо любое количество параметров
 * существует конструктуры для особых задач(копирование или перемещения)
 * конструктор может быть вызван только один раз
 *
 * деструктор спец метод предназначеный для уничтожения обьекта
 * называеться так же как клас только в начале ставиться ~
 * деструктор не получает параметров он может быть только 1
 * деструктор может быть виртуальным
 *
 * cуществует гарантия от стандарта что диструктор будет позван всегда даже в исключительной ситуации
 *
 * try
 *   {
 *       //код программы
 *   }
 *   catch(expertion &e)
 *   {
 *     обработка;
 *   }
 *   catch(....)
 *   {
 *     обработка;
 *   }
 *  return 0;
 *
 */
