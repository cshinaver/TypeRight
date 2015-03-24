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
        Background();
        Background(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        void setTexturePath(string path);
    private:
        double db; // derivative of background over time, speed coef of each background
};

#endif
