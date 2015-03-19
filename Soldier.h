/*
 * Soldier.h
 * Charles Shinaver
 * Example concrete sprite class
*/

#ifndef SOLDIER_H
#define SOLDIER_H

#include "Sprite.h"
#include "SDLWrapper.h"
#include "TRTexture.h"

/*############## FOR DEMO PURPOSES ONLY ############## */
/*############## Header ############################## */

class Soldier : public Sprite
{
    public:
        Soldier(TRTexture tex);
        virtual void move();
};

#endif
