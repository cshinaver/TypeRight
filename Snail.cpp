/*############## .cpp ############################### */
#include "Snail.h"

Snail::Snail() : Sprite()
{
    /*
     * Default constructor. 
    */

    setTexturePath("snail.png");
    setChromaColor(0xFF, 0xFF, 0xFF);
}

void Snail::setTexture(TRTexture tex)
{
    /*
     * Loads texture and sets settings.
    */

    Sprite::setTexture(tex);
    vector<SDL_Rect> clips;
    setCurrentFrame(0);
    setTotalFrames(0);

    /* Spritesheet is 1x3, so calculate height and width of each clip */
    int rows = 1;
    int cols = 3;
    double unitCol = tex.getWidth() / cols;
    double unitRow = tex.getHeight() / rows;

    for (int i = 0; i < cols; i++)
    {
        // Set Snail equal to first row sprites
        SDL_Rect frame;
        frame.w = unitCol;
        frame.h = unitRow;
        frame.x = unitCol * i;
        frame.y = 0; 

        clips.push_back(frame);
    }

    setPos(200, 280);
    setTextureClips(clips);
    setWidth(100);
    setHeight(100);
}

void Snail::move()
{
    int tFrames = getTotalFrames();
    int speedConst = 16; // Modify this to make sprite animation faster or slower
    setCurrentFrame(tFrames / speedConst);
    tFrames++;
    setTotalFrames(tFrames);


    if (tFrames / speedConst >= (int)textureClips.size())
    {
        tFrames = 0;
        setTotalFrames(tFrames);
    }

}
