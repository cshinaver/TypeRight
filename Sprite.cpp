/*
 * Sprite.cpp
 * Charles Shinaver
 * Sprite abstract class implementation file
*/

#include "Sprite.h"

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
}

void Sprite::setTextureClips(vector<SDL_Rect> texClips)
{
    textureClips = texClips;
}
