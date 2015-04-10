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

    if (numSprites() != 2)
    {
        Bruh *b = new Bruh();
        Skeleton *s = new Skeleton();
        b->setText("Hello");
        s->setText("Hello");

        b->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .25);
        s->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .5);
        b->setSize(100, 100);
        s->setSize(100, 100);
        addSprite(b);
        addSprite(s);
    }

}

void Level1::startLevel()
{
    /*
     * Starts level
     */
    Level::startLevel();
}
