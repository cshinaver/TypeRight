/*############## .cpp ############################### */
#include "Bruh.h"

Bruh::Bruh() : Sprite()
{
    /*
     * Default constructor. 
    */

    setTexturePath("pirate.png");
    setChromaColor(0x20, 0xB5, 0x62);
    setDirection(0);
    setDt(1);
}

void Bruh::setTexture(TRTexture tex)
{
    /*
     * Loads texture and sets settings.
    */

    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    /* Spritesheet is 4x3, so calculate height and width of each clip */
    int rows = 4;
    int cols = 3;
    double unitCol = tex.getWidth() / cols;
    double unitRow = tex.getHeight() / rows;

    for (int i = 0; i < rows; i++)
    {
        // Set bruh equal to second column sprites
        SDL_Rect frame;
        frame.w = unitCol;
        frame.h = unitRow;
        frame.x = unitCol;
        frame.y = unitRow * i;

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

void Bruh::move()
{
    int tFrames = getTotalFrames();
    int speedConst = 8 * getDt();   // Modify this to make sprite animation faster or slower
    setCurrentFrame(tFrames / speedConst);
    tFrames++;
    setTotalFrames(tFrames);

    if (tFrames / speedConst >= (int)textureClips.size())
    {
        tFrames = 0;
        setTotalFrames(tFrames);
    }

    // MOVEMENT
    // 0 = right; 1 = left
    // changes direction based on screen position
    if (getPosX() < 0 && getDirection() == 1)
        setDirection(0);
    else if (getPosX() > 640 && getDirection() == 0)
        setDirection(1);

    // gets direction and moves sprite based on it
    if (getDirection() == 0)
        setPos(getPosX() + getDt(), getPosY());
    else
        setPos(getPosX() - getDt(), getPosY());

}
