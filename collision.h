// Elliott Runburg
// Collision header
// collision.h

#ifndef COLLISION_H
#define COLLISION_H

#include “Sprite.h”

class Collision() {
	public:
		Collision();
		Collision(vector < Sprite * > sprites);
		int checkCollision();
        	int isDead();
	private:
		vector< Sprite * > spr;
		Sprite * hero;
};

#endif
