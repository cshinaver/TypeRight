#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <sstream>
#include "SDLWrapper.h"
#include "SpriteFactory.h"
#include "Sprite.h"
#include "Collision.h"
#include "Background.h"
#include "Level.h"

class GameOver : public Level
{
    public:
	GameOver(SDLWrapper &_sw);
	void display() const;
	void generateSprites() {};
	int handleKeyboardEvents();
	int gameOverPlay();
    private:
	SDLWrapper &sw;
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	int selected;
};

#endif
