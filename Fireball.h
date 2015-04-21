/*
 * Fireball.h
 * Charles Shinaver
 * Example concrete sprite class
*/

#ifndef FIREBALL_H
#define FIREBALL_H

#include "Sprite.h"
#include "TRTexture.h"

/*############## Header ############################## */

class Fireball : public Sprite
{
    public:
        Fireball();
        Fireball(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
};

#endif
