/*
 * TypeRight.cpp
 * Charles Shinaver
 * Main game implementation
*/

#include "TypeRight.h"
#include "Bruh.h"
#include "Background.h"

void backgroundDemoFunction(SDLWrapper &sw);

TypeRight::TypeRight()
{
    /*
     * Default constructor
    */

    bgX=0; // background starts at beginning, leftmost x coordinate of texture
    bgY=0; // doesn't change

    // Init window and initial surface
    sw.init();

    //initializes textures
    backgroundTex = sw.loadTexture("typeRightBackground1Double.png", 0, 0, 0xFF, 0xFF);
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

//    Background backk(sw.loadTexture("background3.png")); // mysterious blue+purple
//   Background backk(sw.loadTexture("typeRightBackground1Double.png")); // original, field and sky
//   Background backk(sw.loadTexture("background4.png")); // morris inn
//   Background backk(sw.loadTexture("background5.png")); // city at night
//   Background backk(sw.loadTexture("background6.png")); // purple forrest
//    Background backk(sw.loadTexture("background2.png")); // gross USA map
    
    Background *back = new Background;
    sprites.push_back(back);
    
    Bruh *b = new Bruh;
    sprites.push_back(b);
    // For demo
    while (!quit)
    {
        // Check for keyboard events
        checkForEvents();

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

    // Free textures
    backgroundTex.freeTexture();
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

void backgroundDemoFunction(SDLWrapper &sw)
{
    /*
     * Similar to demoFunction above, except with background1 this time
    */
/*
    TRTexture back = sw.loadTexture("typeRightBackground1.png"); // new background
    sw.renderTextureToWindow(back);
    TRTexture foo = sw.loadTexture("foo.png", 1, 0, 0xFF, 0xFF);
    SDL_Rect renderQuad = {sw.SCREEN_WIDTH / 2, sw.SCREEN_HEIGHT / 2, foo.getWidth(), foo.getHeight()};
    sw.renderTextureToWindow(foo, NULL, &renderQuad);
*/
}

