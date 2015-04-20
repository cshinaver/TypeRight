/*
 * Level.h
 * Charles Shinaver
 * Level Base Class
*/

#ifndef LEVEL_H
#define LEVEL_H
#include <SDL2/SDL.h>
#include <sstream>
#include "SDLWrapper.h"
#include "SpriteFactory.h"
#include "Background.h"
#include "Sprite.h"
#include "Collision.h"

class Level
{
    public:
        Level(SDLWrapper &_sw, int _spritesToKill = 20);
        int startLevel(int currentLevel);
        void setBackground(Background *_back);
        void endLevel();
        void endGame();
        void addSprite(Sprite *);
        SpriteFactory * getEnemyFactory();
        void setEnemyFactory(SpriteFactory *_sf);
        int numSprites();
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
    private:
        Background *levelBackground;
        vector<Sprite *> levelSprites;
        void calculateLevelProgress();
        void loadAndMoveSprites();
        void levelFinished();
        void handleKeyboardEvents();
        void displayInput();
        void displayScore();
        void checkForDefeatedSprites();
        void spriteDefeated(int spriteIndex);
        void checkForHeroDeath();
        virtual void generateSprites() = 0;
        int levelEnded;
        int gameEnded;
        int nextLevel;
        int spritesDefeated;
        const int totalSpritesToKill;
        double globalSpeedModifier; // Globaly changes speed
        SDLWrapper &sw;
        Collision cd;
        SpriteFactory *sf;
        string pressedChars;
};

#endif
