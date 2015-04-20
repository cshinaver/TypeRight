/*
 * Level.cpp
 * Charles Shinaver
 * Level Base Class implementation
*/

#include "Level.h"
#include <stdexcept>


Level::Level(SDLWrapper &_sw, int _spritesToKill) : SCREEN_WIDTH(_sw.SCREEN_WIDTH), SCREEN_HEIGHT(_sw.SCREEN_HEIGHT), totalSpritesToKill(_spritesToKill), sw(_sw)
{
    /*
     * Default base constructor
    */

    levelEnded = 0;
    levelBackground = NULL;
    gameEnded = 0;
    cd.setSpriteVector(&levelSprites);
    spritesDefeated = 0;
    globalSpeedModifier = 0;
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

    s->setIsHero();

    addSprite(s);

    while (!levelEnded)
    {
        // Make changes based on number of defeated sprites
        calculateLevelProgress();
        handleKeyboardEvents();
        generateSprites();
        generatePowerups();

        checkForHeroDeath();
        checkForDefeatedSprites();
        checkForActivatedPowerups();
        checkForIncorrectChars();

        // Clear screen
        SDL_SetRenderDrawColor(sw.renderer, 0xFF, 0xFF, 0xFF, 0xFF );        
        sw.clearWindow();

        loadAndMoveSprites();
        loadAndMovePowerups();
        displayInput();
        displayScore();
        
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

    int x, y;
    int bufferZone = 50;
    // Load and move every sprite
    for (vector<Sprite *>::iterator i = levelSprites.begin(); i != levelSprites.end(); i++)
    {
        sw.loadSprite(*i);

        // If not background or hero, move towards hero
        if (i > levelSprites.begin() + 1)
        {
            // Check if offscreen
            x = (*i)->getPosX();
            y = (*i)->getPosY();
            if (
                x > SCREEN_WIDTH + bufferZone ||
                x < 0 - bufferZone ||
                y > SCREEN_HEIGHT + bufferZone ||
                y < 0 - bufferZone
            )
            {
                delete (*i);
                levelSprites.erase(i);
                continue;
            }
            (*i)->move();
            // Add global speed modifier
            (*i)->setPos((*i)->getPosX() + -1 * globalSpeedModifier, (*i)->getPosY());
        }
        (*i)->animate();
    }

}

void Level::loadAndMovePowerups()
{
    /*
     * Loads and moves powerups
    */

    int x,y, bufferZone;
    bufferZone = 50;

    for (int i = 0; i < (int)powerUpSprites.size(); i++)
    {
        // Dealloc powerups if out of range
        x = powerUpSprites[i]->getPosX();
        y = powerUpSprites[i]->getPosY();
        if (
                x > SCREEN_WIDTH + bufferZone ||
                x < 0 - bufferZone ||
                y > SCREEN_HEIGHT + bufferZone ||
                y < 0 - bufferZone
           )
        {
            delete powerUpSprites[i];
            powerUpSprites.erase(powerUpSprites.begin() + i);
            continue;
        }

        // Load, move, and animate
        sw.loadSprite(powerUpSprites[i]);

        // Move back up if powerup down part of screen
        if (y > .25 * SCREEN_HEIGHT)
        {
            powerUpSprites[i]->setDirection(UP);
        }
        powerUpSprites[i]->move();
        powerUpSprites[i]->animate();
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

SpriteFactory * Level::getEnemyFactory()
{
    return sf;
}

void Level::setEnemyFactory(SpriteFactory *_sf)
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

    double x = 20;
    double y = 20;

    // Display square input box
    sw.displayImage("inputBox.png", x - 6, y, 0, SCREEN_HEIGHT/11, 1, 0xf1, 0x0b, 0xc3 );
    
    // Display typed text
    if ((int)pressedChars.size())
    {
        sw.displayText(pressedChars, x, y);
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
            spriteDefeated(2);
        }
    }

}
void Level::checkForActivatedPowerups()
{
    /*
     * Check for active powerups
    */
    if ((int)powerUpSprites.size() >= 1)
    {
        Sprite *firstPowerup = powerUpSprites[0];
        if (pressedChars == firstPowerup->getText()) // Remove if match
        {
            delete powerUpSprites[0];
            powerUpSprites.erase(powerUpSprites.begin() + 0);
            pressedChars.clear();
        }
    }
}

void Level::checkForIncorrectChars()
{
    /*
     * Checks if input characters don't match word or powerup
    */

    int matches = 0;
    Sprite *firstPowerup;
    Sprite *firstEnemy;
    if (powerUpSprites.size() > 0)
    {
        firstPowerup = powerUpSprites[0];
        if (firstPowerup->getText().substr(0, pressedChars.size()) == pressedChars)
            matches = 1;
    }
    if (levelSprites.size() > 2)
    {
        firstEnemy = levelSprites[2];
        if (firstEnemy->getText().substr(0, pressedChars.size()) == pressedChars)
            matches = 1;
    }

    if (!matches)
    {
        pressedChars.clear();
    }

}
void Level::checkForHeroDeath()
{
    /*
     * Ends game if hero is dead
    */

    if (cd.isDead())
    {
        endGame();
    }
}
void Level::spriteDefeated(int spriteIndex)
{
    /*
     * Occurs when sprite defeated
    */

    delete levelSprites[spriteIndex];
    levelSprites.erase(levelSprites.begin() + spriteIndex);
    spritesDefeated++;
    pressedChars.clear();
}

void Level::displayScore()
{
    /*
     * Displays defeated sprites
    */

    int x, y;
    x = SCREEN_WIDTH - 130;
    y = 20;
    ostringstream strStream;
    strStream << "Score: " << spritesDefeated;
    sw.displayText(strStream.str(), x, y);
}

void Level::calculateLevelProgress()
{
    /*
     * Calculates level progress
    */

    double dg = 1.8;

    // Check defeated number of sprites
    // if greater or equal to half, increase speed
    if (spritesDefeated >= .5 * totalSpritesToKill)
    {
        globalSpeedModifier = dg;
    }

    if (spritesDefeated == totalSpritesToKill)
    {
        endLevel();
    }
}

SpriteFactory * Level::getPowerupFactory()
{
    /*
     * Returns powerup factory
    */

    return powerupFactory;
}

void Level::setPowerupFactory(SpriteFactory *_pf)
{
    powerupFactory = _pf;
}

void Level::generatePowerups()
{
    /*
     * Generates powerups
     * Only generates if one is not in play
    */

    Sprite *s = NULL;
    SpriteFactory *pf = getPowerupFactory();
    s = pf->generateSprites();

    // Check if new sprite added
    if (s != NULL && powerUpSprites.size() != 1)
    {
        // Set position
        s->setPos(SCREEN_WIDTH * .75, 20);
        s->setDirection(DOWN);
        powerUpSprites.push_back(s);
    }
    else if (s != NULL && powerUpSprites.size() >= 1)
    {
        delete s;
    }

}
