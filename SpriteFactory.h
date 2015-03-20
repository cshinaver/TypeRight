/*
 * SpriteFactory.h
 * Charles Shinaver
 * Sprite Factory class
*/

#ifndef SPRITEFACTORY_H
#define SPRITEFACTORY_H

#include "Sprite.h"
#include "Bruh.h"
class SpriteFactory
{
    public:
        SpriteFactory();
        Sprite * getSprite(int typeDesired);
};

#endif