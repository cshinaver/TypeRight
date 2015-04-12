/*
 * SpriteFactory.h
 * Charles Shinaver
 * Sprite Factory class
*/

#ifndef SPRITEFACTORY_H
#define SPRITEFACTORY_H

#include <vector>
#include "Sprite.h"
#include "Cat.h"
#include "Bruh.h"
#include "Skeleton.h"
#include "Snail.h"
#include "Soldier.h"

enum SpriteType
{
    TBruh,
    TCat,
    TSkeleton,
    TSnail,
    TSoldier,
};

class SpriteFactory
{
    public:
        SpriteFactory(int generationFrequency, vector<SpriteType>allowedSprites); // 0 to 100
        Sprite * getSprite(int typeDesired);
        Sprite * generateSprites();
};

#endif
