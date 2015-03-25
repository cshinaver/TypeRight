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

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class Sprite 
{
    friend class SDLWrapper;
    public:
        Sprite();
        virtual ~Sprite();
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
        void setSize(int w, int h);
        virtual void setTexture(TRTexture tex);
        void setTextureClips(vector<SDL_Rect> texClips);
        void setTexturePath(string path) { texturePath = path; };
        string getTexturePath() { return texturePath; };
        int getCurrentFrame() { return currentFrame; };
        void setCurrentFrame(int x) { currentFrame = x; };
        int getTotalFrames() { return totalFrames; };
        void setTotalFrames(int x) { totalFrames = x; };
        double getDt() { return dt; };
        int getIsTextureLoaded() { return isTextureLoaded; };
        void setDt(double _dt) { dt = _dt; };
        void setChromaColor(uint8_t r, uint8_t g, uint8_t b);
        Color getChromaColor() { return chromaColor; };
        int getShouldChroma() { return shouldChroma; };
        void destroySprite();
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
        int currentFrame;
        int totalFrames;
        int isTextureLoaded;
        double dt;
        Color chromaColor;
        int shouldChroma;

};

#endif
