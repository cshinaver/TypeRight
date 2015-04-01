/*
 * TypeRight.cpp
 * Charles Shinaver + Jared Rodgers + Madelyn Nelson + Elliott Runburg
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
#include "Level2.h"
#include "Level3.h"

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
  
    Level3 l3(sw);
    l3.startLevel();

//    Level2 l2(sw);
//    l2.startLevel();

//    Level1 l1(sw);
//    l1.startLevel();

    // Quit SDL
    sw.quit();

}
