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
#include <vector>
#include "Sprite.h"
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
        vector<Sprite *> sprites;
};

#endif
