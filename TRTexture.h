/*
 * TRTexture.h
 * Charles Shinaver
 * TypeRight texture class
 * Stores Texture itself, as well as dimensions. Deals with memory allocation
 * by deallocating when object deallocs.
*/

#ifndef TRTEXTURE_H
#define TRTEXTURE_H

#include <SDL2/SDL.h>

class TRTexture
{
    friend class SDLWrapper;
    public:
        TRTexture(SDL_Texture *, SDL_Surface *); // Texture for storing, surface for dimensions
        int isTextureLoaded();
        void freeTexture();
        int getWidth();
        int getHeight();
    private:
        SDL_Texture *texture;
        int width;
        int height;
};

#endif
