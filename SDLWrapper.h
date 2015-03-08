/*
 * SDLWrapper.h
 * Charles Shinaver
 * Wrapper for SDL engine
*/

#ifndef SDLWRAPPER_H
#define SDLWRAPPER_H
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class SDLWrapper
{
    public:
        SDLWrapper(int h = 480, int w = 640);
        ~SDLWrapper();
        bool init(); // Inits SDL window and initial surface
        void quit(); // Deallocs SDL window and surface
        void updateWindow(); // Updates window surface
        SDL_Window *window;
        SDL_Surface *screenSurface;
        SDL_Surface * loadBmpImg(string);
        SDL_Surface * scaleToScreenSize(SDL_Surface *);
        void scaleToScreenAndBlit(SDL_Surface *);
    private:
        const int SCREEN_HEIGHT;
        const int SCREEN_WIDTH;
};
#endif
