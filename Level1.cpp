/*
 * Level1.cpp
 * Charles Shinaver
 * Level 1 Class implementation
*/

#include "Level1.h"
#include "SpriteFactory.h"

Level1::Level1(SDLWrapper &sw) : Level(sw, "Level 1", 20)
{
    /*
     * Default constructor
    */
    
    /* ####################SETUP BACKGROUND ################ */ 
    Background *background = new Background();
    background->setTexturePath("typeRightBackground1Double.png");

    setBackground(background);

    /* ##################SET ALLOWED SPRITES############### */
    vector<SpriteType> vs;
    vector<SpriteType> powerupSprites;
    vs.push_back(TSkeleton);
    vs.push_back(TSnail);
    vs.push_back(TCat);
    vs.push_back(TBruh);

    powerupSprites.push_back(TSlowDownPowerup);
    SpriteFactory *_sf = new SpriteFactory(100, vs, "level1.txt", SCREEN_WIDTH, SCREEN_HEIGHT);
    SpriteFactory *_pf = new SpriteFactory(600, powerupSprites, "level1.txt", SCREEN_WIDTH, SCREEN_HEIGHT);

    setEnemyFactory(_sf);
    setPowerupFactory(_pf);
    
}

void Level1::generateSprites()
{
    /*
     * Handles sprite generation
    */

    Sprite *s = NULL;
    SpriteFactory *sf = getEnemyFactory();
    s = sf->generateSprites();

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
