/*
 * SDLWrapper.h
 * Charles Shinaver
 * Wrapper for SDL engine
 * This wrapper uses SDL Rendering to display images
*/

#ifndef SDLWRAPPER_H
#define SDLWRAPPER_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <map>
#include "TRTexture.h"
#include "Sprite.h"

using namespace std;

struct TRFont
{
    TTF_Font *fontPtr;
    int fontSize;
};

class SDLWrapper
{
    public:
        SDLWrapper(int h = 480, int w = 640);
        ~SDLWrapper();
        bool init(); // Inits SDL window and initial surface
        void quit(); // Deallocs SDL window and surface
        void updateWindow(); // Updates window surface
        void clearWindow(); // Clears window
        void renderTextureToWindow(TRTexture, SDL_Rect* = NULL, SDL_Rect* = NULL); // Renders texture to window
        SDL_Surface * loadImg(string);
        TRTexture loadTexture(string imgPath,
                int shouldChroma = 0,
                uint8_t r = -1,
                uint8_t g = 0,
                uint8_t b = 0
                ); // Pass pixel to chroma key, empty for none
        TRTexture loadText(
                string text,
                int fontSize = 28,
                uint8_t r = 0,
                uint8_t g = 0,
                uint8_t b = 0,
                string fontStr = "OpenSans-Regular.ttf"
                ); // TTF_Text
        TRFont getFont(string fontStr,int fontSize);
        void loadSprite(Sprite *);
        const int SCREEN_HEIGHT;
        const int SCREEN_WIDTH;
        SDL_Window *window;
        SDL_Surface *screenSurface;
        SDL_Renderer *renderer;
    private:
        map<string, TRFont> fonts;
};

#endif
