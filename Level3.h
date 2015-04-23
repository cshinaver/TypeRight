/*
 * Level3.h
 * Charles Shinaver
 * Level 3 Class
*/

#ifndef LEVEL3_H
#define LEVEL3_H
#include "Level.h"

class Level3 : public Level
{
    public:
        Level3(SDLWrapper &sw);
        int startLevel();
    private:
        void handleKeyboardEvents();
        void generateSprites();


};

#endif
