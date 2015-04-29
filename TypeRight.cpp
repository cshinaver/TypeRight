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
#include "Cat.h"
#include "Snail.h"
#include "SpriteFactory.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "GameOver.h"
#include <unistd.h>

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

    // Set next level
    int nextLevel = 1;
    int play = 1;

    //##################
    //# Main Game Loop #
    //##################

    // instanitate all levels
//    Level1 l1(sw); // easiest, country field background
//    Level2 l2(sw); // middle, scary night city
//    Level3 l3(sw); // hardest, Notre Dame

    while (nextLevel)
    {
	Level1 l1(sw);
	Level2 l2(sw);
	Level3 l3(sw);

        switch (nextLevel) // 0 will kill the program, 4 will show a winning screen, 5 will show a losing screen
        {
            case 1:
               nextLevel = l1.startLevel();
               break;
            case 2:
               nextLevel = l2.startLevel();
               break;
            case 3:
               nextLevel = l3.startLevel();    
               break;
	    case 4:
               // This is where a winning scenario would go
	       break;
 	    case 5:
	       GameOver gg(sw); // Game over screen
	       nextLevel = gg.gameOverPlay();
	       break;
        }
    }

    // Quit SDL
    sw.quit();

}
