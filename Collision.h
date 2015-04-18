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
        void setSpriteVector(vector<Sprite *> *vs);
	private:
	    void setHero();
		vector< Sprite * > * spr;
		Sprite * hero;
};

#endif
