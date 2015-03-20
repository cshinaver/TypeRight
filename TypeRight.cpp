/*
 * TypeRight.cpp
 * Charles Shinaver
 * Main game implementation
*/

#include "TypeRight.h"
#include "Bruh.h"
#include "SpriteFactory.h"

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

    SpriteFactory sf;
    sprites.push_back(sf.getSprite(5));
    int frameCount = 0;
    // For demo
    while (!quit)
    {
        // Check for keyboard events
        checkForEvents();

        // Load new sprite every so often
        //if (!(frameCount % 40))
        //{
        //    sprites.push_back(sf.getSprite(5));
        //}
            

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
        frameCount++;
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
