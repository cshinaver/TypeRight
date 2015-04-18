/*
 * Level.h
 * Charles Shinaver
 * Level Base Class
*/

#ifndef LEVEL_H
#define LEVEL_H
#include <SDL2/SDL.h>
#include "SDLWrapper.h"
#include "SpriteFactory.h"
#include "Background.h"
#include "Sprite.h"
#include "Collision.h"

class Level
{
    public:
        Level(SDLWrapper &_sw);
        int startLevel(int currentLevel);
        void setBackground(Background *_back);
        void endLevel();
        void endGame();
        void addSprite(Sprite *);
        SpriteFactory * getFactory();
        void setFactory(SpriteFactory *_sf);
        int numSprites();
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
    private:
        Background *levelBackground;
        vector<Sprite *> levelSprites;
        void loadAndMoveSprites();
        void levelFinished();
        void handleKeyboardEvents();
        void displayInput();
        void checkForDefeatedSprites();
        void checkForHeroDeath();
        virtual void generateSprites() = 0;
        int levelEnded;
        int gameEnded;
        int nextLevel;
        SDLWrapper &sw;
        Collision cd;
        SpriteFactory *sf;
        string pressedChars;
};

#endif
