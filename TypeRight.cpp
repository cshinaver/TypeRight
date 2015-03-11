/*
 * TypeRight.cpp
 * Charles Shinaver
 * Main game implementation
*/

#include "TypeRight.h"

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

    // For demo
    SDL_Surface *hello_world = sw.loadImg("hello_world.bmp");
    while (!quit)
    {
        // Fill surface white
        SDL_BlitSurface(hello_world, NULL, sw.screenSurface, NULL);
        sw.updateWindow();
        checkForEvents();
    }
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
