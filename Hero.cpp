/*############## .cpp ############################### */
#include "Hero.h"

Hero::Hero() : Sprite()
{
    /*
     * Default constructor. 
    */

    setTexturePath("hero.png");
    setChromaColor(0x20, 0xB5, 0x62);
    setDirection(RIGHT);
}

void Hero::setTexture(TRTexture tex)
{
    /*
     * Loads texture and sets settings.
    */

    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    /* Spritesheet is 4x3, so calculate height and width of each clip */
    int rows = 2;
    int cols = 4;
    double unitCol = tex.getWidth() / cols;
    double unitRow = tex.getHeight() / rows;

    for (int i = 0; i < cols; i++)
    {
        // Set bruh equal to second column sprites
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

void Hero::animate()
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


void Hero::move()
{
    // MOVEMENT
    // gets direction and moves sprite based on it
    if (getDirection() == LEFT)
        setPos(getPosX() + getDt(), getPosY());
    else
        setPos(getPosX() - getDt(), getPosY());

}
