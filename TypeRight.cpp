/*
 * TypeRight.cpp
 * Charles Shinaver
 * Main game implementation
*/

#include "TypeRight.h"

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

    // For demo
    while (!quit)
    {
        checkForEvents();

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        demoFunction(sw);

        // Update screen
        sw.updateWindow();
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

void demoFunction(SDLWrapper &sw)
{
    /*
     * For demo purproses
    */
    // Render rectangle
    SDL_Rect fillRect = {sw.SCREEN_WIDTH/4, sw.SCREEN_HEIGHT/4, sw.SCREEN_WIDTH/2, sw.SCREEN_HEIGHT/2,};
    SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0x00, 0x00, 0xFF );        
    SDL_RenderFillRect(sw.renderer, &fillRect);

    // Render green outlined quad
    SDL_Rect outlineRect = { sw.SCREEN_WIDTH  / 6, sw.SCREEN_HEIGHT  / 6, sw.SCREEN_WIDTH  * 2 / 3, sw.SCREEN_HEIGHT  * 2 / 3 };
    SDL_SetRenderDrawColor( sw.renderer, 0x00, 0xFF, 0x00, 0xFF );        
    SDL_RenderDrawRect( sw.renderer, &outlineRect );

    // Draw blue horizontal line
    SDL_SetRenderDrawColor(sw.renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(sw.renderer, 0, sw.SCREEN_HEIGHT / 2, sw.SCREEN_WIDTH, sw.SCREEN_HEIGHT /2);

    // Draw vertical line of yellow dots
    SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0x00, 0xFF);
    for (int i = 0; i < sw.SCREEN_HEIGHT; i += 4)
    {
        SDL_RenderDrawPoint(sw.renderer, sw.SCREEN_WIDTH /2, i);
    }
}
