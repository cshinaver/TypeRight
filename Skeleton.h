/*
 * Skeleton.h
 * Jared Rodgers
 * Concrete sprite class
*/

#ifndef SKELETON_H
#define SKELETON_H

#include "Sprite.h"
#include "TRTexture.h"

/*############## FOR DEMO PURPOSES ONLY ############## */
/*############## Header ############################## */

class Skeleton : public Sprite
{
    public:
        Skeleton();
        Skeleton(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
};

#endif
