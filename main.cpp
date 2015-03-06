/*
 * main.cpp
 * Charles Shinaver
 * Driver for TypeWrite
*/

#include <SDL2/SDL.h>
#include "SDLWrapper.h"
#include <iostream>

using namespace std;

int main()
{
    SDLWrapper sw;
    sw.init();

    // Image surface
    SDL_Surface *img = sw.loadBmpImg("hello_world.bmp");

    // Blit image to surface
    if (img)
    {
        SDL_BlitSurface(img, NULL, sw.screenSurface, NULL);
    }

    sw.updateWindow();
    
    //Wait two seconds
    SDL_Delay( 2000 );

    // Free
    SDL_FreeSurface(img);

    return 0;
}
