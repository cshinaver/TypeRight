/*
 * SlowDownPowerup.cpp
 * Charles Shinaver
 * SlowDown powerup implementation
*/

#include "SlowDownPowerup.h"

SlowDownPowerup::SlowDownPowerup() : Sprite()
{
    /*
     * Default constructor. 
    */

    setTexturePath("powerups.png");
    setChromaColor(0x8f, 0x99, 0x43);
    setDirection(RIGHT);
}

void SlowDownPowerup::setTexture(TRTexture tex)
{
    /*
     * Loads texture and sets settings.
    */

    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    /* Spritesheet is 4x3, so calculate height and width of each clip */
    int cols = 2;
    double unitCol = 21;
    double unitRow = 19;

    for (int i = 0; i < cols; i++)
    {
        // Set SlowDownPowerup equal to second column sprites
        SDL_Rect frame;
        frame.w = unitRow;
        frame.h = unitCol;
        frame.x = 13 + i*unitCol;
        frame.y = 46;

        clips.push_back(frame);
    }

    setTextureClips(clips);

    // If height or width already set, don't reset
    if (!getWidth())
    {
        setWidth(unitCol);
    }
    if (!getHeight())
    {
        setHeight(unitRow);
    }
}

void SlowDownPowerup::animate()
{
    int speedConst = 1;   // Modify this to make sprite animation faster or slower

    /* ####################CYCLE FRAMES ################# */
    int tFrames = getTotalFrames();
    setCurrentFrame(tFrames / speedConst);
    tFrames++;
    setTotalFrames(tFrames);
    if (tFrames / speedConst >= (int)textureClips.size())
    {
        tFrames = 0;
        setTotalFrames(tFrames);
    }
    /* ####################CYCLE FRAMES ################# */
}


void SlowDownPowerup::move()
{
    // MOVEMENT
    // gets direction and moves sprite based on it
    switch (getDirection())
    {
        case LEFT:
        setPos(getPosX() + getDt(), getPosY());
        break;
        case UP:
        setPos(getPosX(), getPosY() - getDt());
        break;
        case DOWN:
        setPos(getPosX(), getPosY() + getDt());
        break;
        case RIGHT:
        setPos(getPosX() - getDt(), getPosY());
        break;
    }
}
