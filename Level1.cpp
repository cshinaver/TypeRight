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

void Level1::handleKeyboardEvents()
{
    /*
     * Checks for any events in queue and responds if any
     * Put responses to events here
    */

    // Event handler
    SDL_Event e;

    // Event handler loop
    while (SDL_PollEvent( &e ) != 0)
    {
        // User quits
        if (e.type == SDL_QUIT)
        {
            endGame();
        }
    }
}

void Level1::generateSprites()
{
    /*
     * Handles sprite generation
    */

    Sprite *s;
    SpriteFactory *sf = getFactory();
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
