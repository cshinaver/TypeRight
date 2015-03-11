/*
 * SDLWrapper.h
 * Charles Shinaver
 * Wrapper for SDL engine
*/

#ifndef SDLWRAPPER_H
#define SDLWRAPPER_H

#define SDL_MAIN_HANDLED
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
        SDL_Surface * loadImg(string);
        SDL_Surface * scaleToScreenSize(SDL_Surface *);
        void scaleToScreenAndBlit(SDL_Surface *);
        SDL_Window *window;
        SDL_Surface *screenSurface;
    private:
        const int SCREEN_HEIGHT;
        const int SCREEN_WIDTH;
};
#endif
