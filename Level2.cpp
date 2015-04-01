/*
 * Level2.cpp
 * Madelyn Nelson   
 * Level 2 Class implementation
*/

#include "Level2.h"
#include "SpriteFactory.h"

Level2::Level2(SDLWrapper &sw) : Level(sw)
{
    /*
     * Default constructor
    */
    
    /* ####################SETUP BACKGROUND ################ */ 
    Background *background = new Background();
    background->setTexturePath("Combinedbackground5-4.png"); // scary city night
    background->setDb(.5); // Background speed

    setBackground(background);
}

void Level2::handleKeyboardEvents()
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

void Level2::generateSprites()
{
    /*
     * Handles sprite generation
    */

    if (numSprites() != 3)
    {
        Bruh *b = new Bruh();
        Cat *c = new Cat();
        Skeleton *s = new Skeleton();

        b->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .25);
        s->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .5);
        c->setPos(SCREEN_WIDTH * .7, SCREEN_HEIGHT * .6);
        b->setSize(100, 100);
        s->setSize(100, 100);
        c->setSize(100, 100);
        addSprite(b);
        addSprite(s);
        addSprite(c);
    }

}

void Level2::startLevel()
{
    /*
     * Starts level
     */
    Level::startLevel();
}