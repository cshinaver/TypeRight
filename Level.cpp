/*
 * Level.cpp
 * Charles Shinaver
 * Level Base Class implementation
*/

#include "Level.h"
#include <stdexcept>

Level::Level(SDLWrapper &_sw) : SCREEN_WIDTH(_sw.SCREEN_WIDTH), SCREEN_HEIGHT(_sw.SCREEN_HEIGHT), sw(_sw) 
{
    /*
     * Default base constructor
    */

    levelEnded = 0;
    levelBackground = NULL;
    gameEnded = 0;

}

int Level::startLevel(int currentLevel)
{
    /*
     * Main level loop
     * Returns whether or not game should end
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

    // Return game ended status
    if (gameEnded)
    {
        return 0;
    }
    else
    {
        return ++currentLevel;
    }
}

void Level::levelFinished()
{
    /*
     * Run when level ended
    */
    // Free all textures
    for (int i = 0; i < (int)levelSprites.size(); i++)
    {
        levelSprites[i]->destroySprite();
        delete levelSprites[i];
    }

}

void Level::endLevel()
{
    levelEnded = 1;
}

void Level::endGame()
{
    levelEnded = 1;
    gameEnded = 1;
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

    double dt = 1;
    // Load and move every sprite
    for (vector<Sprite *>::iterator i = levelSprites.begin(); i != levelSprites.end(); i++)
    {
        sw.loadSprite(*i);

        // If not background or hero, move towards hero
        if (i > levelSprites.begin() + 1)
        {
            (*i)->setPos((*i)->getPosX() - dt, (*i)->getPosY());
        }
        (*i)->move();
    }

}

void Level::setBackground(Background *_back)
{
    levelBackground = _back;
}

int Level::numSprites()
{
    return (levelSprites.size() - 1);
}

SpriteFactory * Level::getFactory()
{
    return sf;
}

void Level::setFactory(SpriteFactory *_sf)
{
    sf = _sf;
}
