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
    SDL_Texture *hello_world = sw.loadTexture("texture.png");
    while (!quit)
    {
        checkForEvents();
        // Clear screen
        sw.clearWindow();

        // Render texture to screen
        sw.renderTextureToWindow(hello_world, NULL, NULL); // Renders texture to window

        // Update screen
        sw.updateWindow();
    }
    SDL_DestroyTexture(hello_world);
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
