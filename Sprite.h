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
#include <iostream>

using namespace std;

class Sprite 
{
    friend class SDLWrapper;
    public:
        virtual void move() = 0;
        int getPosX() { return posX; };
        int getPosY() { return posY; };
        void setPos(int x, int y);
        double getVelX() { return velX; };
        double getVelY() { return velY; };
        void setVel(double _velX, double _velY);
        double getWidth() { return width; };
        void setWidth(int w);
        double getHeight() { return height; };
        void setHeight(int h);
        void setTexture(TRTexture tex);
        void setTextureClips(vector<SDL_Rect> texClips);
        void setTexturePath(string path) { texturePath = path; };
        bool isAnimated;
        TRTexture textureSrc;
        vector<SDL_Rect> textureClips;
    private:
        string texturePath;
        int posX;
        int posY;
        double velX;
        double velY;
        int width;
        int height;

};

#endif