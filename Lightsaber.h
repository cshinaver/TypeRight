/*
 * Lightsaber.h
 * Charles Shinaver
 * Example concrete sprite class
*/

#ifndef LIGHTSABER_H
#define LIGHTSABER_H

#include "Sprite.h"
#include "TRTexture.h"

/*############## Header ############################## */

class Lightsaber : public Sprite
{
    public:
        Lightsaber();
        Lightsaber(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
};

#endif
