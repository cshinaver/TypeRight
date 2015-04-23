/*
 * Level.cpp
 * Charles Shinaver
 * Level Base Class implementation
*/

#include "Level.h"
#include <stdexcept>

Level::Level(SDLWrapper &_sw, string _levelText, int _spritesToKill) 
    : SCREEN_WIDTH(_sw.SCREEN_WIDTH),
    SCREEN_HEIGHT(_sw.SCREEN_HEIGHT),
    totalSpritesToKill(_spritesToKill),
    levelText(_levelText),
    sw(_sw)
{
    /*
     * Default base constructor
    */

    levelEnded = 0;
    levelBackground = NULL;
    levelBegun = 0;
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
    heroPtr = new Hero;
    Sprite *s = heroPtr;

    // Set defaults for hero
    sf->setDefault(s);

    // Set position of hero
    s->setPos(-400, s->getPosY());

    s->setIsHero();

    addSprite(s);

    // Show level intro
    levelIntro();

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
        loadAndMoveThrownWeapon();

        handleActivatedLevelModifiers();
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

void Level::levelIntro()
{
    /*
     * Shows intro level text, moves hero onscreen
    */

    Sprite *hero = levelSprites[1];
    double dt = hero->getDt();
    double desiredX = .0125 * SCREEN_WIDTH;
    globalSpeedModifier = -1 * dt * 2;
    while(hero->getPosX() < desiredX && !levelEnded)
    {
        loadAndMoveSprites();
        handleKeyboardEvents();
        // Move hero since not done by first method

        sw.displayText(levelText, SCREEN_WIDTH / 2.3, SCREEN_HEIGHT / 8, 30);

        // Update screen
        sw.updateWindow();

    }
    levelBegun = 1;
    globalSpeedModifier = 0;
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
    int bufferZone = 250;
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
        else if (i == levelSprites.begin() + 1 && !levelBegun)
        {
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
    bufferZone = 200;

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

        if (i == 0)
        {
            powerUpSprites[i]->setPos(powerUpSprites[1]->getPosX() + 22, powerUpSprites[1]->getPosY() - 15);
        }
        else if (i == 1)
        {
            powerUpSprites[i]->animate();
        }

        powerUpSprites[i]->move();

        // Check if crossed border
        if (i == ((int)powerUpSprites.size() - 1) && y < 0 - 80 && x > SCREEN_WIDTH / 2)
        {
            delete powerUpSprites[i];
            powerUpSprites.erase(powerUpSprites.begin() + i);
            delete powerUpSprites[i - 1];
            powerUpSprites.erase(powerUpSprites.begin() + i - 1);
        }
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

            if ((int)thrownWeaponSprites.size()==0)
            {
                heroPtr->setAttacking(1);
                heroPtr->setAttackFlag(1);
                generateThrownWeapon();
            }
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
            // Call twice to switch to proper frame
            firstPowerup->animate();
            firstPowerup->animate();
            powerUpActivated(firstPowerup);
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


    double defaultChange;

    // Check defeated number of sprites
    // if greater or equal to half, increase speed
    if (spritesDefeated >= .5 * totalSpritesToKill)
    { 
        defaultChange = levelSprites[1]->getDt();
        if (globalSpeedModifier != defaultChange)
        {
            if (!isModifierActive())
            {
                globalSpeedModifier = defaultChange;
            }
        }
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
    if (s != NULL && powerUpSprites.size() == 0 && !isModifierActive())
    {
        // Spawn pegasus
        Pegasus *p = new Pegasus;
        p->xOffset = 270;
        p->yOffset = 0;

        // Set position
        p->setPos(SCREEN_WIDTH/3, -90);
        s->setPos(SCREEN_WIDTH/3, -90);
        s->setSize(40, 40);
        s->setDirection(DOWN);
        powerUpSprites.push_back(s);
        powerUpSprites.push_back(p);

    }
    else if (s != NULL && powerUpSprites.size() >= 1)
    {
        delete s;
    }

}

void Level::powerUpActivated(Sprite *powerUp)
{
    /*
     * Gets powerup from sprite
    */

    int totalDuration = 300;
    LevelModifier lm;
    lm.duration = totalDuration;
    lm.type = powerUp->activateLevelModifier();

    activeModifiers.push_back(lm);

}

void Level::handleActivatedLevelModifiers()
{
    /*
     * Handles level modifiers
    */

    if (activeModifiers.size() == 0)
        return;

    LevelModifier lm;
    for (int i = 0; i < (int)activeModifiers.size(); i++)
    {
        lm = activeModifiers[i];

        // Handle level modifications 
        switch (lm.type)
        {
            case LEVEL_UNMODIFIED:
                activeModifiers.erase(activeModifiers.begin() + i);
                return;
                break;
            case SLOW_LEVEL:
                if (lm.duration == 0)
                {
                    globalSpeedModifier = 0;
                    activeModifiers.erase(activeModifiers.begin() + i);
                }
                else
                {
                    double dt = levelSprites[1]->getDt();
                    globalSpeedModifier = -1 *dt*.5;
                    activeModifiers[i].duration--;
                }
        }
    }
}

int Level::isModifierActive()
{
    return ((int)activeModifiers.size() > 0) ? 1 : 0;
}

void Level::generateThrownWeapon()
{
    /*
     * Generates weapon
    */

    // Check if new sprite added
    if(heroPtr->getAttackFlag() && heroPtr->isAttacking())
    {
        cout << "Gen" << endl;
        Lightsaber *l = new Lightsaber;

        // Set position
        l->setPos(heroPtr->getPosX()+20,heroPtr->getPosY()+20);
        l->setSize(50, 50);
        l->setDt(20);
        l->setDirection(LEFT);
        thrownWeaponSprites.push_back(l);
    }
}

void Level::loadAndMoveThrownWeapon()
{
    /*
     * Loads and moves weapons
    */

    int x,y, bufferZone;
    bufferZone = 200;

    for (int i = 0; i < (int)thrownWeaponSprites.size(); i++)
    {
        // Dealloc powerups if out of range
        x = thrownWeaponSprites[i]->getPosX();
        y = thrownWeaponSprites[i]->getPosY();
        if (
                x > SCREEN_WIDTH + bufferZone ||
                x < 0 - bufferZone ||
                y > SCREEN_HEIGHT + bufferZone ||
                y < 0 - bufferZone
           )
        {
            delete thrownWeaponSprites[i];
            thrownWeaponSprites.erase(thrownWeaponSprites.begin() + i);
            continue;
        }

        // Load, move, and animate
        sw.loadSprite(thrownWeaponSprites[i]);

        thrownWeaponSprites[i]->animate();
        thrownWeaponSprites[i]->move();
        if (cd.checkCollision(thrownWeaponSprites[i],levelSprites[2]))
        {
            spriteDefeated(2);
            delete thrownWeaponSprites[i];
            thrownWeaponSprites.erase(thrownWeaponSprites.begin() + i);
        }
        

        // Check if crossed border
        if (i == ((int)thrownWeaponSprites.size() - 1) && y < 0 - 80 && x > SCREEN_WIDTH / 2)
        {
            delete thrownWeaponSprites[i];
            thrownWeaponSprites.erase(thrownWeaponSprites.begin() + i);
            delete thrownWeaponSprites[i - 1];
            thrownWeaponSprites.erase(thrownWeaponSprites.begin() + i - 1);
        }
    }
}

