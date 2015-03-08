/*
 * TypeRight.h
 * Charles Shinaver
 * Main game header
*/

#ifndef TYPERIGHT_H
#define TYPERIGHT_H

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
};

#endif
