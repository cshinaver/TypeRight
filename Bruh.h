/*
 * Bruh.h
 * Charles Shinaver
 * Example concrete sprite class
*/

#ifndef BRUH_H
#define BRUH_H

#include "Sprite.h"
#include "SDLWrapper.h"
#include "TRTexture.h"

/*############## FOR DEMO PURPOSES ONLY ############## */
/*############## Header ############################## */

class Bruh : public Sprite
{
    public:
        Bruh();
        Bruh(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
};

#endif
