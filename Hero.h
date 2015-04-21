/*
 * Hero.h
 * Charles Shinaver
 * Example concrete sprite class
*/

#ifndef HERO_H
#define HERO_H

#include "Sprite.h"
#include "TRTexture.h"

/*############## Header ############################## */

class Hero : public Sprite
{
    public:
        Hero();
        Hero(TRTexture tex);
        void setTexture(TRTexture tex);
        virtual void move();
        virtual void animate();
        virtual void attack();
        int isAttacking() { return attacking; };
        void setAttacking(int _a) { attacking = _a; };
        void setAttackFlag(int _af) { attackFlag = _af; };

    private:
        int attacking;
        int attackFlag;
        vector<Sprite> sabers;
        
};

#endif
