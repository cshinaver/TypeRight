#include "Skeleton.h"

Skeleton::Skeleton() : Sprite()
{
    /*
     * Default constructor. 
    */

    setTexturePath("skeleton.png");
    setChromaColor(0x9D, 0x8E, 0x87);
    setDirection(RIGHT);
}

void Skeleton::setTexture(TRTexture tex)
{
    /*
     * Loads texture and sets settings.
    */
    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    /* Spritesheet is 1x6, so calculate height and width of each clip */
    int rows = 1;
    int cols = 6;
    double unitCol = tex.getWidth() / cols;
    double unitRow = tex.getHeight() / rows;

    for (int i = 0; i < cols; i++)
    {
        // Set Skeleton equal to first row sprites
        SDL_Rect frame;
        frame.w = unitCol;
        frame.h = unitRow;
        frame.x = unitCol * i;
        frame.y = 0;

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

void Skeleton::animate()
{
    int tFrames = getTotalFrames();
    int speedConst = 8; // Modify this to make sprite animation faster or slower
    setCurrentFrame(tFrames / speedConst);
    tFrames++;
    setTotalFrames(tFrames);


    if (tFrames / speedConst >= (int)textureClips.size())
    {
        tFrames = 0;
        setTotalFrames(tFrames);
    }

}

void Skeleton::move()
{
    // MOVEMENT
    // gets direction and moves sprite based on it
    if (getDirection() == LEFT)
        setPos(getPosX() + getDt(), getPosY());
    else
        setPos(getPosX() - getDt(), getPosY());

}
