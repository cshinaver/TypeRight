/*############## .cpp ############################### */
#include "Hero.h"

Hero::Hero() : Sprite()
{
    /*
     * Default constructor. 
    */

    setTexturePath("hero.png");
    setChromaColor(0xFF, 0x00, 0xFF);
    setDirection(RIGHT);
    setAttacking(0);
    setAttackFlag(0);
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

    /* Spritesheet is 2x4, so calculate height and width of each clip */
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
    
    for (int i = 0; i < cols; i++)
    {
        // Set bruh equal to second column sprites
        SDL_Rect frame;
        frame.w = unitCol;
        frame.h = unitRow;
        frame.x = unitCol * i;
        frame.y = unitRow;

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
    setTotalFrames(tFrames);
    if (isAttacking())
    {
        if (attackFlag)
        {
            tFrames = textureClips.size()/2;
            setCurrentFrame(tFrames);
            setAttackFlag(0);
        }
        else
        {
            setCurrentFrame(tFrames / speedConst + textureClips.size()/2);
        }
        tFrames++;
        setTotalFrames(tFrames);
        if (tFrames / speedConst >= (int)textureClips.size()/2)
        {
            tFrames = 0;
            setTotalFrames(tFrames);
            setAttacking(0);
        }
    }
    else
    {
        setCurrentFrame(tFrames / speedConst);
        tFrames++;
        setTotalFrames(tFrames);
        if (tFrames / speedConst >= (int)textureClips.size()/2)
        {
            tFrames = 0;
            setTotalFrames(tFrames);
        }
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

void Hero::attack()
{
    int speedConst = 8;   // Modify this to make sprite animation faster or slower

    /* ####################CYCLE FRAMES ################# */
    int tFrames = getTotalFrames();
    setCurrentFrame(tFrames / speedConst);
    tFrames++;
    setTotalFrames(tFrames);
    cout << "Running correct 4" << endl;
    if (tFrames / speedConst >= (int)textureClips.size())
    {
        tFrames = 0;
        setTotalFrames(tFrames);
//        attacking = 0;
    }
    /* ####################CYCLE FRAMES ################# */
}
