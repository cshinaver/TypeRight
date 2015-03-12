/*
 * SDLWrapper.cpp
 * Charles Shinaver
 * Implementation for wrapper for SDL engine
*/

#include "SDLWrapper.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdexcept>

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
        return success;
    }
    //Create window
    window = SDL_CreateWindow( "TypeWrite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError();
        success = false; 
        return success;
    }

    // Init SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) &imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        success = false; 
        return success;
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    return success;
}

void SDLWrapper::updateWindow()
{
    /*
     * Updates main window
     */

    SDL_UpdateWindowSurface( window);
}

SDL_Surface * SDLWrapper::loadImg(string imgName)
{
    /*
     * Opens image from img directory and returns surface for that image
    */

    string fullImgPath = "../imgs/" + imgName;
    SDL_Surface *img = NULL;
    SDL_Surface *optimizedSurface = NULL;

    // Image surface
    img = IMG_Load(fullImgPath.c_str());
    if (img == NULL)
    {
        cout << "Unable to load image " << fullImgPath << "! SDL Error: " << SDL_GetError() << endl;
        throw runtime_error("Unable to load image");
    }

    return img;
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
