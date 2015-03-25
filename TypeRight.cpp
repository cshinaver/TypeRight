/*
 * TypeRight.cpp
 * Charles Shinaver + Jared Rodgers
 * Main game implementation
*/

#include "TypeRight.h"
#include "Bruh.h"
#include "Background.h"
#include "Soldier.h"
#include "Skeleton.h"
#include "Snail.h"
#include "SpriteFactory.h"
#include "Level1.h"

TypeRight::TypeRight()
{
    /*
     * Default constructor
    */

    // Init window and initial surface
    sw.init();

}

void TypeRight::startGame()
{
    /*
     * Starts game
    */

    // Set quit status
    quit = false;

    //##################
    //# Main Game Loop #
    //##################

    // For demo
    SpriteFactory sf;
    
    Level1 l1(sw);
    l1.startLevel();

    // Quit SDL
    sw.quit();

}
