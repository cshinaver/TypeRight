/*
 * TypeRight.cpp
 * Charles Shinaver + Jared Rodgers
 * Main game implementation
*/

#include "TypeRight.h"
#include "Bruh.h"
<<<<<<< HEAD
#include "Soldier.h"
#include "Skeleton.h"
=======
#include "SpriteFactory.h"
>>>>>>> master

void demoFunction(SDLWrapper &sw);

TypeRight::TypeRight()
{
    /*
     * Default constructor
    */
}

void TypeRight::startGame()
{
    /*
     * Starts game
    */

    // Init window and initial surface
    sw.init();

    // Set quit status
    quit = false;

    //##################
    //# Main Game Loop #
    //##################

    Bruh *b = new Bruh;
    Soldier *sol = new Soldier;
    Skeleton *skel = new Skeleton;
    sprites.push_back(b);
    sprites.push_back(sol);
    sprites.push_back(skel);

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
