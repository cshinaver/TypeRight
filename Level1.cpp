/*
 * Level1.cpp
 * Charles Shinaver
 * Level 1 Class implementation
*/

#include "Level1.h"
#include "SpriteFactory.h"

Level1::Level1(SDLWrapper &sw) : Level(sw)
{
    /*
     * Default constructor
    */
    
    /* ####################SETUP BACKGROUND ################ */ 
    Background *background = new Background();
    background->setTexturePath("typeRightBackground1Double.png");
    background->setDb(.3); // Background speed

    setBackground(background);

    /* ##################SET ALLOWED SPRITES############### */
    vector<SpriteType> vs;
    vs.push_back(TSkeleton);
    vs.push_back(TCat);
    SpriteFactory *_sf = new SpriteFactory(100, vs, SCREEN_WIDTH, SCREEN_HEIGHT);

    setFactory(_sf);
    
}

void Level1::generateSprites()
{
    /*
     * Handles sprite generation
    */

    Sprite *s = NULL;
    SpriteFactory *sf = getFactory();
    //s = sf->generateSprites();
    if (numSprites() != 2)
    {
        s = sf->getSprite(8);
        sf->setDefault(s);
        s->setText("hello");
    }

    // Check if new sprite added
    if (s != NULL)
    {
        addSprite(s);
    }
}

int Level1::startLevel()
{
    /*
     * Starts level
     */
    return Level::startLevel(1);
}
