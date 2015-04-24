// menu.h

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SDL2/SDL.h>
#include <sstream>
#include "SDLWrapper.h"
#include "SpriteFactory.h"
#include "Sprite.h"
#include "Collision.h"
#include "Background.h"

//using namespace std;

class Menu {
    public:
        Menu(SDLWrapper &_sw);
        void menuPlay();
        void display() const;
        void handleKeyboardEvents();
        int checkForPlayActivation();
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
    private:
        int pressedPlay(); // 1 if play is pressed, 0 if not
        int pressedQuit(); // 1 if quit is pressed, 0 if not
        SDLWrapper &sw;
        int playActivation;
};

#endif
