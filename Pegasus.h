/*
 * Pegasus.h
 * Jared Rodgers
*/

#ifndef PEGASUS_H
#define PEGASUS_H

#include "Sprite.h"
#include "TRTexture.h"

/*############## FOR DEMO PURPOSES ONLY ############## */
/*############## Header ############################## */

class Pegasus : public Sprite
{
    public:
        Bruh();
        Bruh(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
};

#endif
