/*
 * SlowDownPowerup.h
 * Charles Shinaver
 * SlowDown powerup sprite class
*/

#ifndef SLOWDOWNPOWERUP_H
#define SLOWDOWNPOWERUP_H

#include "Sprite.h"
#include "TRTexture.h"

class SlowDownPowerup : public Sprite
{
    public:
        SlowDownPowerup();
        SlowDownPowerup(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
};

#endif
