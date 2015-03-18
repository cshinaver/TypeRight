/*############## .cpp ############################### */
#include "Bruh.h"

Bruh::Bruh(TRTexture tex)
{
    setTexture(tex);
    vector<SDL_Rect> clips;

    /* Spritesheet is 4x3, so calculate height and width of each clip */
    int rows = 4;
    int cols = 3;
    double unitRow = tex.getWidth() / cols;
    double unitCol = tex.getHeight() / rows;

    for (int i = 0; i < rows; i++)
    {
        // Set bruh equal to second column sprites
        SDL_Rect frame;
        frame.w = unitCol;
        frame.h = unitRow;
        frame.x = unitCol * i;
        frame.y = unitRow * i;

        clips.push_back(frame);
    }

    setPos(50, 50);
    setTextureClips(clips);
    setWidth(unitCol);
    setHeight(unitRow);
}

void Bruh::move()
{
}