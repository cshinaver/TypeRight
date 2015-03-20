/*
 * SpriteFactory.cpp
 * Charles Shinaver
 * Sprite Factory class implementation
*/

#include "SpriteFactory.h"

SpriteFactory::SpriteFactory()
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
    
    /* EXAMPLE. DON'T DO THIS */

    static int x = 0;
    int y = 100;
    cout << x << endl;
    x += 100;

    if (x > 500)
        x = 0;

    /*########################*/

    Sprite *s = new Bruh;
    s->setPos(x, y);
    return s;
}
