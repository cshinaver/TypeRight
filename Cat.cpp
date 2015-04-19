#include "Cat.h"

Cat::Cat() : Sprite()
{
    /*
     * Default constructor. 
     */

    setTexturePath("runningcat.png");
    setChromaColor(255, 255, 255);
    setDirection(RIGHT);
}

void Cat::setTexture(TRTexture tex)
{
    /*
     * Loads texture and sets settings.
     */
    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    /* Spritesheet is 1x6, so calculate height and width of each clip */
    int rows = 4;
    int cols = 2;
    double unitCol = tex.getWidth() / cols;
    double unitRow = tex.getHeight() / rows;

    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            // Set Skeleton equal to first row sprites
            SDL_Rect frame;
            frame.w = unitCol;
            frame.h = unitRow;
            frame.x = unitCol * i;
            frame.y = unitRow * j;

            clips.push_back(frame);
        }
    }
    setTextureClips(clips);
// cat needs width:height ratio 4:3
}

void Cat::move()
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

void Cat::animate()
{
    // MOVEMENT
    // gets direction and moves sprite based on it
    if (getDirection() == LEFT)
        setPos(getPosX() + getDt(), getPosY());
    else
        setPos(getPosX() - getDt(), getPosY());
}
