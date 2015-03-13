/*
 * TRTexture.cpp
 * Charles Shinaver
 * TypeRight texture implementation
*/

#include "TRTexture.h"
#include <stdexcept>

using namespace std;


TRTexture::TRTexture(SDL_Texture *_texture, SDL_Surface *_surface)
{
    /*
     * Allocate with string of filename 
    */

    if (_texture == NULL)
    {
        throw runtime_error("Passed texture was null");
    }

    texture = _texture;
    width = _surface->w;
    height = _surface->h;

    // Free unneeded surface
    SDL_FreeSurface(_surface);
}

void TRTexture::freeTexture()
{
    /*
     * Frees texture
    */
    SDL_DestroyTexture(texture);
    texture = NULL;
}

int TRTexture::isTextureLoaded()
{
    /*
     * Checks if texture loaded
    */

    if (texture == NULL)
        return 0;
    else
        return 1;
}

int TRTexture::getWidth()
{
    return width;
}

int TRTexture::getHeight()
{
    return height;
}
