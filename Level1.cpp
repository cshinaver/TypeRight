/*
 * Level1.cpp
 * Charles Shinaver
 * Level 1 Class implementation
*/

#include "Level1.h"

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
}

void Level1::startLevel()
{
    /*
     * Starts level
     */
    Level::startLevel();
}
