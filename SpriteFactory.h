/*
 * SpriteFactory.h
 * Charles Shinaver
 * Sprite Factory class
*/

#ifndef SPRITEFACTORY_H
#define SPRITEFACTORY_H

#include <vector>
#include <fstream>
#include "Sprite.h"
#include "Cat.h"
#include "Bruh.h"
#include "Skeleton.h"
#include "Snail.h"
#include "Soldier.h"
#include "SlowDownPowerup.h"

enum SpriteType
{
    TBruh,
    TCat,
    TSkeleton,
    TSnail,
    TSoldier,
    TSlowDownPowerup,
};

class SpriteFactory
{
    public:
        SpriteFactory(
                int _generationFrequency,
                vector<SpriteType>_allowedSprites,
                string wordBankFilepath,
                int _SCREEN_WIDTH,
                int _SCREEN_HEIGHT
                ); // 0 to 100
        Sprite * getSprite(int typeDesired);
        Sprite * generateSprites();
        void setDefault(Sprite * _s);
    private:
        const vector<SpriteType> allowedSprites;
        const int generationFrequency;
        vector<string> wordBank;
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
};

#endif
