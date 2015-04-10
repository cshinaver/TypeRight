/*
 * Cat.h
 * Madelyn Nelson
 * Concrete sprite class
*/

#ifndef CAT_H
#define CAT_H

#include "Sprite.h"
#include "TRTexture.h"

class Cat : public Sprite
{
    public:
        Cat();
        Cat(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
};

#endif
