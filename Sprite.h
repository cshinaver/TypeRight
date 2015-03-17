/*
 * Sprite.h
 * Charles Shinaver
 * Sprite abstract class
*/

#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include "TRTexture.h"
#include <vector>

using namespace std;

class Sprite 
{
    public:
        virtual void move() = 0;
        int getPosX() { return posX; };
        int getPosY() { return posY; };
        void setPos(int x, int y) : posX(x), posY(y);
        double getVelX() { return velX; };
        double getVelY() { return velY; };
        void setVel(double _velX, double _velY) : velX(_velX), velY(_velY);
        int getWidth() { return width; };
        void setWidth(int w) : width(w);
        int getHeight() { return height; };
        void setHeight(int h) : height(h);
        void setTexture(TRTexture *tex) : textureSrc(tex);
        void setTextureClips(vector<SDL_Rect> texClips) : textureClips(texClips);
        bool isAnimated;
    private:
        TRTexture *textureSrc;
        vector<SDL_Rect> textureClips;
        int posX;
        int posY;
        double velX;
        double velY;
        int width;
        int height;

};
#endif
