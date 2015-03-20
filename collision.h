#ifndef COLLISION_H
#define COLLISION_H

#include “Sprite.h”

class Collision() {
	public:
		Collision();
		int checkCollision(Sprite * a, Sprite * b);
};

#endif