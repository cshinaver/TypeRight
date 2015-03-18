/*
 * TypeRight.cpp
 * Charles Shinaver
 * Main game implementation
*/

#include "TypeRight.h"
#include "Bruh.h"

void demoFunction(SDLWrapper &sw);
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

    // For demo
    int count=0;
    while (!quit)
    {
        checkForEvents();

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        //demoFunction(sw);
        //backgroundDemoFunction(sw); // tests the new background
        cout << "count=" << count << endl; // counts while loop iterations
        count++;

        //Scroll Background is somewhere near here???????
        scrollBackground();

        // Update screen
        sw.updateWindow();
    }

    // Quit SDL
    sw.quit();

    // Free textures
    backgroundTex.freeTexture();
}

void TypeRight::scrollBackground()
{
    double backFract = .5;
    // Offset of the background
    bgX+=4;
    if (bgX >= backgroundTex.getWidth()*(1-backFract) ) // background1 is 951 x 521 pixels, shouldn't hard code this. FIX LATER!!

        //if (bgX >= backgroundTex.getWidth()*(1-backFract) ) // background1 is 951 x 521 pixels, shouldn't hard code this. FIX LATER!!
    {
        bgX=0; // reset to the beginning of the background
    }	
    //cout << "bgX=" << bgX << endl;


    // destination rectangle
    SDL_Rect src = {bgX, bgY, backgroundTex.getWidth()*backFract, backgroundTex.getHeight()};
    SDL_Rect dest = {0, 0, sw.SCREEN_WIDTH, sw.SCREEN_HEIGHT};
    sw.renderTextureToWindow(backgroundTex, &src, &dest);
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

    Bruh b(sw.loadTexture("pirate.png", 1, 0x20, 0xB5, 0x62));
    sw.loadSprite(&b);
}

void backgroundDemoFunction(SDLWrapper &sw)
{
    /*
     * Similar to demoFunction above, except with background1 this time
    */

    TRTexture back = sw.loadTexture("typeRightBackground1.png"); // new background
    sw.renderTextureToWindow(back);
    TRTexture foo = sw.loadTexture("foo.png", 1, 0, 0xFF, 0xFF);
    SDL_Rect renderQuad = {sw.SCREEN_WIDTH / 2, sw.SCREEN_HEIGHT / 2, foo.getWidth(), foo.getHeight()};
    sw.renderTextureToWindow(foo, NULL, &renderQuad);
}


