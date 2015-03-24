/*
 * Level1.cpp
 * Charles Shinaver
 * Level 1 Class implementation
*/

#include "Level1.h"

Level1::Level1()
{
    /*
     * Default constructor
    */
    
    /* ####################SETUP BACKGROUND ################ */ 
    levelBackground = new Background();
    levelBackground->setTexturePath("typeRightBackground1Double.png");
    levelBackground->setDb(.3); // Background speed

    // Add background to vector
    levelSprites.push_back(levelBackground);
}

void Level1::startLevel()
{
    /*
     * Starts level
     */
}



