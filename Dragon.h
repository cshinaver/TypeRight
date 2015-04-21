/*
 * Dragon.h
 * Charles Shinaver
 * Example concrete sprite class
*/

#ifndef DRAGON_H
#define DRAGON_H

#include "Sprite.h"
#include "TRTexture.h"

/*############## Header ############################## */

class Dragon : public Sprite
{
    public:
        Dragon();
        Dragon(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
};

#endif
