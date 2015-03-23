#ifndef COLLISION_CPP
#define COLLISION_CPP

#include “collision.h”

Collision::Collision() {}

Collision::Collision(Sprite * h, vector< Sprite * > a)
{
    hero = h;
    spr = a;
}

int Collision::isDead() {
    for ( int i = 0; i < a.size(); i++ ) {
        if ( checkCollision(hero, spr[i]) )
            return 1;
    }
    return 0;
}

int Collision::checkCollision(Sprite * a, Sprite * b) {
	int minX1, minX2, maxX1, maxX2, minY1, minY2, maxY1, maxY2;
	minX1 = (*a).getPosX();
	maxX1 = (*a).getPosX()+(*a).getWidth();
	minX2 = (*b).getPosX();
	maxX2 = (*b).getPosX()+(*b).getWidth();
	minY1 = (*a).getPosY();
	maxY1 = (*a).getPosY()+(*a).getHeight();
	minY2 = (*b).getPosY();
	maxY2 = (*b).getPosY()+(*b).getHeight();
	
	bool xOverlap = false;
	bool yOverlap = false;

	if ( (minX1 >= minX2 && minX1 <= maxX2) || (maxX1 >= minX2 && maxX1 <= maxX2) )
		xOverlap = true;
	if ( (minY1 >= minY2 && minY1 <= maxY2) || (maxY1 >= minY2 && maxY1 <= maxY2) )
		yOverlap = true;

	if ( xOverlap == true && yOverlap == true )
		return 1;
	else
		return 0;
}

#endif