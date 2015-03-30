/*
 * main.cpp
 * Charles Shinaver
 * Driver for TypeWrite
*/

#include "TypeRight.h"
#include <SDL2/SDL_image.h>
#include "collision.h"

int main()
{
    TypeRight tr;
    tr.startGame();
    Collision * coll=new Collision();
    return 0;
}
