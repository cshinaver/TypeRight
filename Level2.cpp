/*
 * Level2.cpp
 * Charles Shinaver
 * Level 2 Class implementation
*/

#include "Level2.h"
#include "SpriteFactory.h"

Level2::Level2(SDLWrapper &sw) : Level(sw, "Level 2", 20)
{
    /*
     * Default constructor
    */
    
    /* ####################SETUP BACKGROUND ################ */ 
    Background *background = new Background();
    background->setTexturePath("Combinedbackground5-4.png");

    setBackground(background);

    /* ##################SET ALLOWED SPRITES############### */
    vector<SpriteType> vs;
    vector<SpriteType> powerupSprites;
    vs.push_back(TSkeleton);
    vs.push_back(TSnail);
    vs.push_back(TCat);

    powerupSprites.push_back(TSlowDownPowerup);
    SpriteFactory *_sf = new SpriteFactory(100, vs, "level2.txt", SCREEN_WIDTH, SCREEN_HEIGHT);
    SpriteFactory *_pf = new SpriteFactory(600, powerupSprites, "level2.txt", SCREEN_WIDTH, SCREEN_HEIGHT);

    setEnemyFactory(_sf);
    setPowerupFactory(_pf);
    
}

void Level2::generateSprites()
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

int Level2::startLevel()
{
    /*
     * Starts level
     */
    return Level::startLevel(2);
}
