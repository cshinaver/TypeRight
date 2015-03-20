/*############## .cpp ############################### */
#include "Soldier.h"

Soldier::Soldier() : Sprite()
{
    /*
     * Default constructor. 
    */

    setTexturePath("soldier.png");
    setChromaColor(0x4D, 0x4B, 0x76);
}

void Soldier::setTexture(TRTexture tex)
{
    /*
     * Loads texture and sets settings.
    */

    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    /* Spritesheet is 2x8, so calculate height and width of each clip */
    int rows = 2;
    int cols = 8;
    double unitCol = tex.getWidth() / cols;
    double unitRow = tex.getHeight() / rows;

    for (int i = 0; i < cols; i++)
    {
        // Set Soldier equal to second row sprites
        SDL_Rect frame;
        frame.w = unitCol;
        frame.h = unitRow;
        frame.x = unitCol * i;
        frame.y = unitRow; 

        clips.push_back(frame);
    }

    setPos(200, 80);
    setTextureClips(clips);
    setWidth(unitCol);
    setHeight(unitRow);
}

void Soldier::move()
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
