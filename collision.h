#ifndef COLLISION_H
#define COLLISION_H

#include “Sprite.h”

class Collision() {
	public:
		Collision();
		Collision(Sprite * hero, vector < Sprite * > sprites);
		int checkCollision();
        int isDead();
	private:
		vector< Sprite * > spr;
        Sprite * hero;
};

#endif