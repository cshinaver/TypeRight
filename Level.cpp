/*
 * Level.cpp
 * Charles Shinaver
 * Level Base Class implementation
*/

#include "Level.h"
#include <stdexcept>

Level::Level(SDLWrapper &_sw) : sw(_sw)
{
    /*
     * Default base constructor
    */

    levelEnded = 0;
    levelBackground = NULL;
}

void Level::startLevel()
{
    /*
     * Main level loop
    */

    // Load background into vector first
    if (levelBackground == NULL)
    {
        throw logic_error("Level background not set.");
    }
    else
    {
        addSprite(levelBackground);
    }

    while (!levelEnded)
    {
        handleKeyboardEvents();
        generateSprites();

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        loadAndMoveSprites();

        // Update screen
        sw.updateWindow();
    }

    levelFinished();
}

void Level::levelFinished()
{
    /*
     * Run when level ended
    */
    // Free all textures
    for (vector<Sprite *>::iterator i = levelSprites.begin(); i != levelSprites.end(); i++)
    {
        (*i)->destroySprite();
        delete (*i);
    }
}

void Level::endLevel()
{
    levelEnded = 1;
}

void Level::addSprite(Sprite *s)
{
    levelSprites.push_back(s);
}

void Level::loadAndMoveSprites()
{
    /*
     * Loads and moves sprites
    */
    // Load and move every sprite
    for (vector<Sprite *>::iterator i = levelSprites.begin(); i != levelSprites.end(); i++)
    {
        sw.loadSprite(*i);
        (*i)->move();
    }

}

void Level::setBackground(Background *_back)
{
    levelBackground = _back;
}