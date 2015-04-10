/*
 * Level3.cpp
 * Madelyn Nelson   
 * Level 3 Class implementation
*/

#include "Level3.h"
#include "SpriteFactory.h"

Level3::Level3(SDLWrapper &sw) : Level(sw)
{
    /*
     * Default constructor
    */
    
    /* ####################SETUP BACKGROUND ################ */ 
    Background *background = new Background();
    background->setTexturePath("Combinedbackground9-9.png"); // ND
    background->setDb(.35); // Background speed

    setBackground(background);
}

void Level3::handleKeyboardEvents()
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

void Level3::generateSprites()
{
    /*
     * Handles sprite generation
    */

    if (numSprites() != 2)
    {
        Bruh *b = new Bruh();
        Skeleton *s = new Skeleton();

        b->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .25);
        s->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .5);
        b->setSize(100, 100);
        s->setSize(100, 100);
        addSprite(b);
        addSprite(s);
    }

}

void Level3::startLevel()
{
    /*
     * Starts level
     */
    Level::startLevel();
}
