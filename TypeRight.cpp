/*
 * TypeRight.cpp
 * Charles Shinaver
 * Main game implementation
*/

#include "TypeRight.h"
#include "Bruh.h"

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

    Bruh b(sw.loadTexture("pirate.png", 1, 0x20, 0xB5, 0x62));
    // For demo
    while (!quit)
    {
        checkForEvents();

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        //b.setWidth(300);
        //b.setHeight(400);
        sw.loadSprite(&b);
        b.move();

        // Update screen
        sw.updateWindow();
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
