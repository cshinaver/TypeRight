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
     * Handles keyboard input
    */
}

void Level1::generateSprites()
{
    /*
     * Handles sprite generation
    */
}

void Level1::startLevel(SDLWrapper &sw)
{
    /*
     * Starts level
     */
    Level::startLevel(sw);
}
