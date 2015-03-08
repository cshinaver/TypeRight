/*
 * SDLWrapper.cpp
 * Charles Shinaver
 * Implementation for wrapper for SDL engine
*/

#include "SDLWrapper.h"
#include <iostream>

using namespace std;

SDLWrapper::SDLWrapper(int h, int w) : SCREEN_WIDTH(w), SCREEN_HEIGHT(h)
{
    /*
     * Initializes window and gets surface. Stores in variables
    */

    // Initialize pointers to null
    window = NULL;
    screenSurface = NULL;
}

SDLWrapper::~SDLWrapper()
{
    /*
     * Deallocates all stored variables
    */
    quit();
}

void SDLWrapper::quit()
{
    /*
     * Deallocates all stored things
    */

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
}

bool SDLWrapper::init()
{
    // init flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << endl;;
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "TypeWrite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError();
            success = false;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
            return 1;
        }
    }

    return success;
}

void SDLWrapper::updateWindow()
{
    /*
     * Updates main window
     */

    SDL_UpdateWindowSurface( window);
}

SDL_Surface * SDLWrapper::loadBmpImg(string imgName)
{
    /*
     * Opens image from img directory and returns surface for that image
    */

    string fullImgPath = "../imgs/" + imgName;
    SDL_Surface *img = NULL;
    SDL_Surface *optimizedSurface = NULL;

    // Image surface
    img = SDL_LoadBMP(fullImgPath.c_str());
    if (img == NULL)
    {
        cout << "Unable to load image " << fullImgPath << "! SDL Error: " << SDL_GetError() << endl;
    }
    else
    {
        // Convert image surface to screen format
        optimizedSurface = SDL_ConvertSurface(img, screenSurface->format, 0);
        if (optimizedSurface == NULL)
        {
            cout << "Unable to optimize image " << imgName << "! SDL Error: " << SDL_GetError() << endl;
        }

        SDL_FreeSurface(img);

    }

    return optimizedSurface;
}

void SDLWrapper::scaleToScreenAndBlit(SDL_Surface * img)
{
    /*
     * Scales image to screen size
    */
    //Apply the image stretched
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;
    SDL_BlitScaled(img, NULL, screenSurface, &stretchRect );

}
