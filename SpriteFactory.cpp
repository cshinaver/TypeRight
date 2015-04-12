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
        vector<enum SpriteType>_allowedSprites,
        int _SCREEN_WIDTH,
        int _SCREEN_HEIGHT
        ) : 
    allowedSprites(_allowedSprites),
    generationFrequency(_generationFrequency),
    SCREEN_WIDTH(_SCREEN_WIDTH),
    SCREEN_HEIGHT(_SCREEN_HEIGHT)
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
    if (!(count % generationFrequency) && count != 0)
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
        

        // Set default sprite settings
        setDefault(s);
        count = 0;
    }
    else
    {
        count++;
    }

    return s;
}

void SpriteFactory::setDefault(Sprite * _s)
{
    /*
     * Sets sprite default characteristsics
    */

    _s->setPos(SCREEN_WIDTH * 17./20, SCREEN_HEIGHT * .625);
    _s->setSize(100, 100);

}
