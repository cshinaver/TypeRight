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
    
    /* Demo purposes */
    int demoSpriteGenerated = 0;
    /* ############# */
    while (!quit)
    {
        // Check for keyboard events
        checkForEvents();

        // Generate sprites
        if (!demoSpriteGenerated)
        {
            Sprite *s1 = sf.getSprite(0); // Make enums
            Sprite *s2 = sf.getSprite(1);
            s2->setPos(300, 50);
            sprites.push_back(s1);
            sprites.push_back(s2);
            demoSpriteGenerated = 1;
        }

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        // Load and move every sprite
        for (vector<Sprite *>::iterator i = sprites.begin(); i != sprites.end(); i++)
        {
            sw.loadSprite(*i);
            (*i)->move();
        }

        // Update screen
        sw.updateWindow();
    }

    // Free all textures
    for (vector<Sprite *>::iterator i = sprites.begin(); i != sprites.end(); i++)
    {
        (*i)->destroySprite();
        delete (*i);
    }
    
    // Quit SDL
    sw.quit();

}

void TypeRight::checkForEvents()
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
            quit = true;
        }
    }
}
