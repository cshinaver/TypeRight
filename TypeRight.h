/*
 * TypeRight.h
 * Charles Shinaver
 * Main game header
*/

#ifndef TYPERIGHT_H
#define TYPERIGHT_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "SDLWrapper.h"
#include <iostream>

using namespace std;

class TypeRight
{
    public:
        TypeRight();
        void startGame();
    private:
        SDLWrapper sw;
        bool quit;
        void checkForEvents(); // Checks for events and responds to them
	void scrollBackground(); // scrolls through the background
	int bgX; // Scrolling background, x coord offset, eventually
		// should be in terms of dt
	int bgY;
};

#endif
