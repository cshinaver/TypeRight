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

SDLWrapper::SDLWrapper(int h, int w) : SCREEN_HEIGHT(h), SCREEN_WIDTH(w)
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
    
    // Init SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) &imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        success = false; 
        return success;
    }

    // Init SDL_ttf
    if (TTF_Init() == -1)
    {
        cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
        return success;
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    // Set render draw color
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return success;
}

void SDLWrapper::quit()
{
    /*
     * Deallocates all stored things
     */

    // Destroy Surface 
    SDL_FreeSurface(screenSurface);

    // Free fonts
    for (map<FontKey, TRFont>::iterator i = fonts.begin(); i != fonts.end(); i++)
    {
        TTF_Font *font = i->second.fontPtr;
        TTF_CloseFont(font);
        i->second.fontPtr = NULL;
    }

    // Free Renderer
    SDL_DestroyRenderer(renderer);

    //Destroy window
    SDL_DestroyWindow( window );


    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
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

void SDLWrapper::renderTextureToWindow(
        TRTexture _texture,
        SDL_Rect *clip,
        SDL_Rect *dest,
        double angleOfRotation,
        int flip
    )
{
    /*
     * Renders texture to window
    */

    SDL_RendererFlip desiredFlip;
    if (flip)
    {
        desiredFlip = SDL_FLIP_HORIZONTAL;
    }
    else
        desiredFlip = SDL_FLIP_NONE;

    SDL_RenderCopyEx(renderer, _texture.texture, clip, dest, angleOfRotation, NULL, desiredFlip);
}

void SDLWrapper::loadSprite( Sprite * _sprite)
{
    /*
     * Loads given sprite
    */

    // Check if sprite has a loaded texture
    if (!(_sprite->getIsTextureLoaded()))
    {
        Color chromaColor = _sprite->getChromaColor();
        int shouldChroma = _sprite->getShouldChroma();
        _sprite->setTexture(loadTexture(
                    _sprite->getTexturePath(),
                    shouldChroma,
                    chromaColor.r,
                    chromaColor.g,
                    chromaColor.b
                    ));
    }

    // Src clip
    SDL_Rect src = _sprite->textureClips[_sprite->getCurrentFrame()];

    // Dest rect
    SDL_Rect dest;
    dest.x = _sprite->getPosX();
    dest.y = _sprite->getPosY();
    dest.w = _sprite->getWidth();
    dest.h = _sprite->getHeight();

    renderTextureToWindow(_sprite->textureSrc, &src, &dest, 0, _sprite->getFlip());

    // Load sprite text
    // dh and dx between text and sprite
    int dh = 30;
    int dx = 15;
    if (_sprite->getText() != "")
    {
        displayText(_sprite->getText(), _sprite->getPosX() + dx, _sprite->getPosY() - dh);
    }
}

TRTexture SDLWrapper::loadTextIntoTexture(
        string text,
        int fontSize,
        uint8_t r,
        uint8_t g,
        uint8_t b,
        string fontStr
        )
{
    /*
     * Loads text to screen at given position
    */

    SDL_Color textColor = {r, g, b, 0xFF};

    TRFont font = getFont(fontStr, fontSize);
    // Create surface from text
    SDL_Surface *textSurface = TTF_RenderText_Solid(font.fontPtr, text.c_str(), textColor);
    if (textSurface == NULL)
    {
        cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << endl;
    }

    // Create texture from surface
    SDL_Texture *texSrc = SDL_CreateTextureFromSurface(renderer, textSurface);
    TRTexture textTexture = TRTexture(texSrc, textSurface);

    return textTexture;
}

TRFont SDLWrapper::getFont(string fontStr, int fontSize)
{
    /*
     * Returns desired font if exists
     * Checks if font already exists. If so, uses that font.
     * Else, loads new font and adds to font map
    */

    string fontFullname = "../fonts/" + fontStr;

    FontKey fk(fontStr, fontSize);

    // Check if font in map
    if (fonts.count(fk))
    {
        TRFont font = fonts[fk];
        // Check if font size same
        if (fontSize == font.fontSize)
        {
            return font;
        }
    }

    // If not in map, make font
    TRFont newFont;
    newFont.fontSize = fontSize;
    newFont.fontPtr = TTF_OpenFont(fontFullname.c_str(), fontSize);
    fonts.insert(pair<FontKey, TRFont>(fk, newFont));
    return newFont;
}

void SDLWrapper::displayText(string text, int x, int y, int fontSize)
{
    /*
     * Displays text at given position
    */

    // Get text texture
    TRTexture textTex = loadTextIntoTexture(text, fontSize, 0x09, 0x0B, 0x51);

    // Set dimensions for display
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = textTex.getWidth();
    dest.h = textTex.getHeight();

    // Render to screen
    renderTextureToWindow(textTex, NULL, &dest);
}

void SDLWrapper::displayRectangle(int x, int y, int w, int h, SDL_Color c)
{
    /*
     * Displays filled rectangle at given position
    */

    SDL_Rect fillRect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(renderer, &fillRect);
}
void SDLWrapper::displayImage(
        string imgPath,
        int x,
        int y,
        int w,
        int h,
        int shouldChroma,
        uint8_t r,
        uint8_t g,
        uint8_t b
        ) // Pass pixel to chroma key, empty for none
{
    /*
     * Loads given image from path
    */

    TRTexture img = loadTexture(imgPath, shouldChroma, r, g, b);

    // Check if passed size
    if (!w)
        w = img.getWidth();
    if (!h)
        h = img.getHeight();

    SDL_Rect destRect = {x, y, w, h};
    renderTextureToWindow(img, NULL, &destRect);
}

