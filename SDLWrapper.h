/*
 * SDLWrapper.h
 * Charles Shinaver
 * Wrapper for SDL engine
*/

#ifndef SDLWRAPPER_H
#define SDLWRAPPER_H
#include <SDL/SDL.h>

class SDLWrapper
{
    public:
        SDLWrapper(int h = 480, int w = 640);
        ~SDLWrapper();
        int init(); // Inits SDL window and initial surface
        void updateWindow(); // Updates window surface
        SDL_Window *window;
        SDL_Surface *screenSurface;
    private:
        const int SCREEN_HEIGHT;
        const int SCREEN_WIDTH;
};
#endif
