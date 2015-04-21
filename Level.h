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
        Level(SDLWrapper &_sw, string _levelText, int _spritesToKill = 20);
        int startLevel(int currentLevel);
        void setBackground(Background *_back);
        void endLevel();
        void endGame();
        void addSprite(Sprite *);
        SpriteFactory * getEnemyFactory();
        void setEnemyFactory(SpriteFactory *_sf);
        SpriteFactory * getPowerupFactory();
        void setPowerupFactory(SpriteFactory *_pf);
        int numSprites();
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
    private:
        void generatePowerups();
        Background *levelBackground;
        vector<Sprite *> levelSprites;
        vector<Sprite *> powerUpSprites;
        vector<LevelModifier> activeModifiers;
        void levelIntro();
        void calculateLevelProgress();
        void loadAndMoveSprites();
        void loadAndMovePowerups();
        void levelFinished();
        void handleKeyboardEvents();
        void displayInput();
        void displayScore();
        void checkForDefeatedSprites();
        void checkForActivatedPowerups();
        void handleActivatedLevelModifiers();
        void checkForIncorrectChars();
        void spriteDefeated(int spriteIndex);
        void checkForHeroDeath();
        void powerUpActivated(Sprite *powerUp);
        int isModifierActive();
        virtual void generateSprites() = 0;
        int levelEnded;
        int gameEnded;
        int nextLevel;
        int spritesDefeated;
        int levelBegun;
        const int totalSpritesToKill;
        const string levelText;
        double globalSpeedModifier; // Globaly changes speed
        SDLWrapper &sw;
        Collision cd;
        SpriteFactory *sf;
        SpriteFactory *powerupFactory;
        string pressedChars;
        Hero *heroPtr;
};

#endif
