/*
 * Level3.h
 * Madelyn Nelson
 * Level 3 Class
*/

#ifndef LEVEL3_H
#define LEVEL3_H
#include "Level.h"

class Level3 : public Level
{
    public:
        Level3(SDLWrapper &sw);
        void startLevel();
    private:
        void handleKeyboardEvents();
        void generateSprites();


};

#endif
