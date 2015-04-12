/*
 * SpriteFactory.cpp
 * Charles Shinaver
 * Sprite Factory class implementation
*/

#include "SpriteFactory.h"
#include <stdlib.h>
#include <time.h>

SpriteFactory::SpriteFactory(
        int _generationFrequency,
        vector<enum SpriteType>_allowedSprites
        ) : allowedSprites(_allowedSprites), generationFrequency(_generationFrequency)
{
    /*
     * Default constructor
    */

    // Seed rand
    srand(time(NULL));
}

Sprite * SpriteFactory::getSprite(int typeDesired)
{
    /*
     * Returns sprite pointer based on input
    */
    
    Sprite *s = new Bruh;
    return s;
}

Sprite * SpriteFactory::generateSprites()
{
    // Counts frames and generates based on frame number
    Sprite *s = NULL;
    static int count = 0;
    int chosen;
    SpriteType chosenSprite;

    // Get random sprite
    if (!(count % generationFrequency))
    {
        chosen = rand() % allowedSprites.size();
        chosenSprite = allowedSprites[chosen];

        // Select sprite to give
        switch (chosenSprite)
        {
            case TCat:
                s = new Cat;
                break;
            case TSkeleton:
                s = new Skeleton;
                break;
            case TSoldier:
                s = new Soldier;
                break;
            case TBruh:
                s = new Bruh;
                break;
            case TSnail:
                s = new Snail;
                break;
        }
    }

    return s;
}
