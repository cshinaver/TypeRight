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
    init();
}

SDLWrapper::~SDLWrapper()
{
    /*
     * Deallocates all stored variables
    */

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
}

int SDLWrapper::init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << endl;;
        return 0;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "TypeWrite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError();
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
            return 1;
        }
    }

    return 0;
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

    // Image surface
    img = SDL_LoadBMP(fullImgPath.c_str());
    if (img == NULL)
    {
        cout << "Unable to load image " << fullImgPath << "! SDL Error: " << SDL_GetError() << endl;
    }

    return img;
}
