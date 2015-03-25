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

    Background *back = new Background;
    back->setTexturePath("Combinedbackground9-9.png"); // Temporary. Will be set in level class
    sprites.push_back(back);
    
    Bruh *b = new Bruh;
    b->setPos(100, 100);
    Soldier *sol = new Soldier;
    sol->setPos(200, 100);
    Skeleton *skel = new Skeleton;
    skel->setPos(300, 100);
    Snail *sna = new Snail;
    sna->setPos(400, 100);
    sprites.push_back(b);
    sprites.push_back(sol);
    sprites.push_back(skel);
    sprites.push_back(sna);

    // For demo
    SpriteFactory sf;
    
    Level1 l1(sw);
    l1.startLevel();

    // Quit SDL
    sw.quit();

}
