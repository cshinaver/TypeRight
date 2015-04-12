/*
 * SpriteFactory.cpp
 * Charles Shinaver
 * Sprite Factory class implementation
*/

#include "SpriteFactory.h"

SpriteFactory::SpriteFactory(int generationFrequency, vector<enum SpriteType>allowedSprites)
{
    /*
     * Default constructor
    */
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
    static int count;

    
}
