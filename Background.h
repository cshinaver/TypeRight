/*
 * Background.h
 * Madelyn Nelson
 * Background, public sprite class
*/

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Sprite.h"
#include "SDLWrapper.h"
#include "TRTexture.h"

class Background : public Sprite
{
    public:
        Background(TRTexture tex);
        virtual void move();
};

#endif
