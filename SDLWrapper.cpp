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

    // Destroy Surface 
    SDL_FreeSurface(screenSurface);

    // Free Renderer
    SDL_DestroyRenderer(renderer);

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    IMG_Quit();
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
    window = SDL_CreateWindow( "TypeRight", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError();
        success = false; 
        return success;
    }

    // Create renderer 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
        success = false; 
        return success;
    }
    
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) &imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        success = false; 
        return success;
    }



    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    // Set render draw color
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return success;
}

TRTexture SDLWrapper::loadTexture(string imgPath, int shouldChroma, uint8_t r, uint8_t g, uint8_t b)
{
    /*
     * Loads image as surface and converts surface to texture
     * If you want to chroma key a color (eg remove background), pass 1 to
     * shouldChroma, and then pass the r, g, and b values as ints. They can be
     * decimal or Hexadecimal. Anything accepted by SDL.
    */

    // Texture
    SDL_Texture *newTexture = NULL;

    SDL_Surface *loadedSurface = loadImg(imgPath);
    if (loadedSurface == NULL)
    {
        cout << "Unable to load image " << imgPath << "! SDL_image Error: " << IMG_GetError() << endl;
    }

    // Chroma key surface if value passed
    if (shouldChroma)
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));
    }

    // Create texture from Surface
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL)
    {
        cout << "Unable to create texture from " << imgPath << "! SDL Error: " << SDL_GetError() << endl;
    }

    TRTexture newTR = TRTexture(newTexture, loadedSurface);
    return newTR;
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

void SDLWrapper::updateWindow()
{
    /*
     *  Updates window surface
    */
    
    SDL_RenderPresent(renderer);
}

void SDLWrapper::clearWindow()
{
    /*
     * Clears window
    */

    SDL_RenderClear(renderer);
}

void SDLWrapper::renderTextureToWindow(TRTexture _texture, SDL_Rect *clip, SDL_Rect *dest)
{
    /*
     * Renders texture to window
    */

    SDL_RenderCopy(renderer, _texture.texture, clip, dest);
}
