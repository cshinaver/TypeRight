/*
 * Level.h
 * Charles Shinaver
 * Level Base Class
*/

#ifndef LEVEL_H
#define LEVEL_H
#include <SDL2/SDL.h>
#include "SDLWrapper.h"
#include "Background.h"
#include "Sprite.h"

class Level
{
    public:
        Level(SDLWrapper &_sw);
        void startLevel();
        void setBackground(Background *_back);
        void endLevel();
        void addSprite(Sprite *);
        int numSprites();
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
    private:
        Background *levelBackground;
        vector<Sprite *> levelSprites;
        void loadAndMoveSprites();
        void levelFinished();
        virtual void handleKeyboardEvents() = 0;
        virtual void generateSprites() = 0;
        int levelEnded;
        SDLWrapper &sw;
};

#endif
