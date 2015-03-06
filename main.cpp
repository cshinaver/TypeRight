/*
 * main.cpp
 * Charles Shinaver
 * Driver for TypeWrite
*/

#include <SDL/SDL.h>
#include "SDLWrapper.h"

int main()
{
    SDLWrapper sw;
    sw.init();

    //Fill the surface white
    SDL_FillRect( sw.screenSurface, NULL, SDL_MapRGB( sw.screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Update the surface
    sw.updateWindow();

    //Wait two seconds
    SDL_Delay( 2000 );

    return 0;
}
