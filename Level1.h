/*
 * Level1.h
 * Charles Shinaver
 * Level 1 Class
*/

#ifndef LEVEL1_H
#define LEVEL1_H
#include "Level.h"

class Level1 : public Level
{
    public:
        Level1();
        virtual void startLevel(SDLWrapper &sw);
};

#endif
