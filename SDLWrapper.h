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
        void renderTextureToWindow(
            TRTexture,
            SDL_Rect* = NULL,
            SDL_Rect* = NULL,
            double angleOfRotation = 0,
            int flip = 0
            ); // Renders texture to window
        void displayText(string text, int x, int y, int fontSize = 28);
        void displayRectangle(int x, int y, int w, int h, SDL_Color c);
        SDL_Surface * loadImg(string);
        void displayImage(
                string imgPath, 
                int x,
                int y,
                int w = 0,
                int h = 0,
                int shouldChroma = 0,
                uint8_t r = -1,
                uint8_t g = 0,
                uint8_t b = 0
                ); // Pass pixel to chroma key, empty for none
        TRTexture loadTexture(string imgPath,
                int shouldChroma = 0,
                uint8_t r = -1,
                uint8_t g = 0,
                uint8_t b = 0
                ); // Pass pixel to chroma key, empty for none
        void loadSprite(Sprite *);
        const int SCREEN_HEIGHT;
        const int SCREEN_WIDTH;
        SDL_Window *window;
        SDL_Surface *screenSurface;
        SDL_Renderer *renderer;
    private:
        TRFont getFont(string fontStr,int fontSize);
        TRTexture loadTextIntoTexture(
                string text,
                int fontSize,
                uint8_t r = 0,
                uint8_t g = 0,
                uint8_t b = 0,
                string fontStr = "OpenSans-Regular.ttf"
                ); // TTF_Text
        map<string, TRFont> fonts;
};

#endif
