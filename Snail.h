/*
 * Snail.h
 * Jared Rodgers
 * Concrete sprite class
*/

#ifndef SNAIL_H
#define SNAIL_H

#include "Sprite.h"
#include "TRTexture.h"

class Snail : public Sprite
{
    public:
        Snail();
        Snail(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
};

#endif
