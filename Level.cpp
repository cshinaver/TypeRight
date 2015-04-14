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

    // Add hero
    Sprite *s = new Bruh;

    // Set defaults for hero
    sf->setDefault(s);

    // Set position of hero
    s->setPos(SCREEN_WIDTH * .0125, s->getPosY());

    addSprite(s);

    while (!levelEnded)
    {
        handleKeyboardEvents();
        generateSprites();

        checkForDefeatedSprites();

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        loadAndMoveSprites();
        displayInput();
        
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

    double dt = 4;
    // Load and move every sprite
    for (vector<Sprite *>::iterator i = levelSprites.begin(); i != levelSprites.end(); i++)
    {
        sw.loadSprite(*i);

        // If not background or hero, move towards hero
        if (i > levelSprites.begin() + 1)
        {
            (*i)->move();
            //(*i)->setPos((*i)->getPosX() - dt, (*i)->getPosY());
        }
        (*i)->animate();
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

void Level::handleKeyboardEvents()
{
    /*
     * Checks for any events in queue and responds if any
     * Put responses to events here
    */

    // Event handler
    SDL_Event e;

    SDL_StartTextInput();

    // Event handler loop
    while (SDL_PollEvent( &e ) != 0)
    {
        switch (e.type)
        {
            case SDL_QUIT:
                endGame();
                break;
            case SDL_TEXTINPUT:
                pressedChars += e.text.text[0];
        }
    }
}

void Level::displayInput()
{
    /*
     * Displays the currently entered text
    */

    if ((int)pressedChars.size())
    {
        sw.displayText(pressedChars, 20, 20);
    }
}

void Level::checkForDefeatedSprites()
{
    /*
     * Checks if any of the sprites have been killed
    */

    if ((int)levelSprites.size() > 2)
    {
        Sprite *firstEnemy = levelSprites[2];
        if (pressedChars == firstEnemy->getText()) // Remove if match
        {
            levelSprites.erase(levelSprites.begin() + 2);
        }
        else if (firstEnemy->getText().substr(0, pressedChars.size()) != pressedChars ) // reset word if exceeds word length
        {
            pressedChars.clear();
        }
    }

}
