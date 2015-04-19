// Elliott Runburg
// Collision definitions
// collision.cpp

#ifndef COLLISION_CPP
#define COLLISION_CPP

#include "Collision.h"
#include <stdexcept>

void setHero();

Collision::Collision() {
	hero = NULL;
}

Collision::Collision(vector< Sprite * > * a)
{
	// Constructor initializing hero sprite as well as vector of sprites
	spr = a;
}

void Collision::setSpriteVector(vector<Sprite *> *vs)
{
    spr = vs;
}

int Collision::isDead() {

    // Finds out if the character is dead or not
    for ( int i = 2; i < (int)spr->size(); i++ ) {
        // Set hero if needed
        if (hero == NULL)
            setHero();

        if (checkCollision(hero, (*spr)[i]))
    		return 1;
    }
    return 0;
}

int Collision::checkCollision(Sprite * a, Sprite * b) {
	// Values with all the positions of the two sprites involved
	int minX1, minX2, maxX1, maxX2, minY1, minY2, maxY1, maxY2;
	minX1 = a->getPosX();
	maxX1 = a->getPosX()+a->getWidth();
	minX2 = b->getPosX();
	maxX2 = b->getPosX()+b->getWidth();
	minY1 = a->getPosY();
	maxY1 = a->getPosY()+a->getHeight();
	minY2 = b->getPosY();
	maxY2 = b->getPosY()+b->getHeight();
	
	bool xOverlap = false;
	bool yOverlap = false;

	// If there is x or y overlap, turn that variable to true, and then if both, return 1.
	if ( (minX1 >= minX2 && minX1 <= maxX2) || (maxX1 >= minX2 && maxX1 <= maxX2) )
		xOverlap = true;
	if ( (minY1 >= minY2 && minY1 <= maxY2) || (maxY1 >= minY2 && maxY1 <= maxY2) )
		yOverlap = true;

	if ( xOverlap == true && yOverlap == true )
		return 1;
	else
		return 0;
}

void Collision::setHero()
{
    /*
     * Sets hero if vector is big enough
    */

    // Check if vector big enough
    if (spr->size() <= 2)
        return;

    if (!(*spr)[1]->isHero())
        throw runtime_error("Hero is not in second vector slot");
    else
        hero = (*spr)[1];
}

#endif
