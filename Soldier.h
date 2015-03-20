/*
 * Soldier.h
 * Jared Rodgers
 * Concrete sprite class
*/

#ifndef SOLDIER_H
#define SOLDIER_H

#include "Sprite.h"
#include "SDLWrapper.h"
#include "TRTexture.h"

/*############## Header ############################## */

class Soldier : public Sprite
{
    public:
        Soldier(TRTexture tex);
        virtual void move();
};

#endif