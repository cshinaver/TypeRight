/*
 * Pegasus.h
 * Jared Rodgers
*/

#ifndef PEGASUS_H
#define PEGASUS_H

#include "Sprite.h"
#include "TRTexture.h"

class Pegasus : public Sprite
{
    public:
        Pegasus();
        Pegasus(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
        double xOffset;
        double yOffset;
    private:
        double t;
};

#endif
