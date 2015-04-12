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
            endGame();
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
    
    if (numSprites() != 3)
    {
        Bruh *b0 = new Bruh();
        Bruh *b1 = new Bruh();
        Skeleton *s = new Skeleton();
        b0->setText("Hello");
        b1->setText("Hello");
        s->setText("Hello");

        b0->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .25);
        b1->setPos(SCREEN_WIDTH * .3, SCREEN_HEIGHT * .3);
        s->setPos(SCREEN_WIDTH * .125, SCREEN_HEIGHT * .5);
        b0->setSize(100, 100);
        b1->setSize(100, 100);
        s->setSize(100, 100);
        addSprite(b0);
        addSprite(b1);
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
