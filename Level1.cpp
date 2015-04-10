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
            endLevel();
        }
    }
}

void Level1::generateSprites()
{
    /*
     * Handles sprite generation
    */

    static int count = 0;

    if (count == 500)
    {
        endLevel();
    }
    else
    {
        count++;
    }

    if (numSprites() != 2)
    {
        Bruh *b = new Bruh();
        Cat *c = new Cat();

        c->setPos(SCREEN_WIDTH * .175, SCREEN_HEIGHT * .65);
        b->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .25);
        c->setSize(160, 120);
        b->setSize(100, 100);
        addSprite(c);
        addSprite(b);
    }

}

void Level1::startLevel()
{
    /*
     * Starts level
     */
    Level::startLevel();
}
