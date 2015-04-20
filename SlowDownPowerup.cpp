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
    double unitCol = 16;
    double unitRow = 17;

    for (int i = 0; i < cols; i++)
    {
        // Set SlowDownPowerup equal to second column sprites
        SDL_Rect frame;
        frame.w = unitCol;
        frame.h = unitRow;
        frame.x = 18 + i*unitCol;
        frame.y = 50;

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
    int speedConst = 8;   // Modify this to make sprite animation faster or slower

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
    if (getDirection() == LEFT)
        setPos(getPosX() + getDt(), getPosY());
    else
        setPos(getPosX() - getDt(), getPosY());

}
