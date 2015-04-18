// Elliott Runburg
// Collision header
// collision.h

#ifndef COLLISION_H
#define COLLISION_H

#include "Sprite.h"
#include <vector>

class Collision {
	public:
		Collision();
		Collision(vector < Sprite * > * sprites);
		int checkCollision(Sprite *, Sprite *);
        int isDead();
	private:
		vector< Sprite * > * spr;
		Sprite * hero;
};

#endif
