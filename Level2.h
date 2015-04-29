/*
 * Level2.h
 * Charles Shinaver
 * Level 2 Class
*/

#ifndef LEVEL2_H
#define LEVEL2_H
#include "Level.h"

class Level2 : public Level
{
    public:
        Level2(SDLWrapper &sw);
        int startLevel();
    private:
        void handleKeyboardEvents();
        void generateSprites();


};

#endif
