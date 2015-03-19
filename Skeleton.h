/*
 * Bruh.h
 * Charles Shinaver
 * Example concrete sprite class
*/

#ifndef SKELETON_H
#define SKELETON_H

#include "Sprite.h"
#include "SDLWrapper.h"
#include "TRTexture.h"

/*############## FOR DEMO PURPOSES ONLY ############## */
/*############## Header ############################## */

class Skeleton : public Sprite
{
    public:
        Skeleton(TRTexture tex);
        virtual void move();
};

#endif
