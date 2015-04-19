/*
 * Sprite.cpp
 * Charles Shinaver
 * Sprite abstract class implementation file
*/

#include "Sprite.h"

Sprite::Sprite()
{
    /*
     * Default constructor
    */

    dt = 4;
    setDirection(RIGHT);
    hero = 0;
    isTextureLoaded = 0;
    shouldChroma = 0;
    setWidth(0);
    setHeight(0);
    text = "";
}

Sprite::~Sprite()
{
    /*
     * Destructor
    */
}

void Sprite::setPos(int x, int y)
{
    posX = x;
    posY = y;
}

void Sprite::setVel(double _velX, double _velY)
{
    velX = _velX;
    velY = _velY;
}

void Sprite::setWidth(int w)
{
    width = w;
}

void Sprite::setHeight(int h)
{
    height = h;
}

void Sprite::setTexture(TRTexture tex)
{
    textureSrc = tex;
    isTextureLoaded = 1;
}

void Sprite::setTextureClips(vector<SDL_Rect> texClips)
{
    textureClips = texClips;
}

void Sprite::destroySprite()
{
    /*
     * Destroys texture to free memory
    */

    textureSrc.freeTexture();
    isTextureLoaded = 0;
}

void Sprite::setChromaColor(uint8_t r, uint8_t g, uint8_t b)
{
    chromaColor.r = r;
    chromaColor.g = g;
    chromaColor.b = b;
    shouldChroma = 1;
}

void Sprite::setSize(int w, int h)
{
    setWidth(w);
    setHeight(h);
}

DirectionType Sprite::getDirection()
{
    return direction;
}

void Sprite::setDirection(DirectionType d)
{
    direction = d;
}

